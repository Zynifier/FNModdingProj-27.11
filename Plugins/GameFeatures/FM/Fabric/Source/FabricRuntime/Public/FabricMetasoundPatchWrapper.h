// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "MetasoundBuilderSubsystem.h"
#include "MetasoundOutput.h"
#include "UObject/NoExportTypes.h"
#include "FabricMetasoundManagerComponent.h"
#include "FabricModulatable.h"
#include "FabricModulatorInterface.h"
#include "FabricMetasoundPatchWrapper.generated.h"

class AActor;
class UAudioComponent;
class UFabricMetaSoundManagerComponent;
class UFabricMetaSoundPatchWrapper;
class UFabricMetaSoundTreeNode;
class UMetaSoundPatch;
class UMetasoundGeneratorHandle;
class UMidiStepSequence;
class UMusicClockComponent;
class USoundSourceBus;

UENUM(BlueprintType)
enum class EFabricMetaSoundPatchWrapperQuality : uint8
{
	High = 0,
	Low = 1,
};

UENUM(BlueprintType)
enum class EFabricMetaSoundPinDirection : uint8
{
	Input = 0,
	Output = 1,
};

UENUM(BlueprintType)
enum class EFabricMetasoundInputType : uint8
{
	ModulatedUserOption = 0,
	NonModulatedUserOption = 1,
	DirectInput = 2,
};

USTRUCT(BlueprintType)
struct FFabricMetaSoundPatchWrapperPeakTamer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperPeakTamer")
	bool bUseGameplaySmoothing;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperPeakTamer")
	bool bSortSignals;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperPeakTamer")
	int32 MaxSignalsToTame;

};

USTRUCT(BlueprintType)
struct FFabricMetaSoundPatchWrapperBinding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperBinding")
	FName FriendlyName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperBinding")
	bool bAllowOnDedicatedServer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapperBinding")
	FFabricMetaSoundPatchWrapperPeakTamer PeakTamer;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricMetaSoundPatchWrapperBinding")
	FName MetaSoundNodeName;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricMetaSoundPatchWrapperBinding")
	TArray<float> Signals;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FabricMetaSoundPatchWrapperBinding")
	bool bBoundToWatchEvents;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricMetaSoundPatchWrapperBindingUpdate, const FFabricMetaSoundPatchWrapperBinding&, Binding);

USTRUCT(BlueprintType)
struct FFabricMetaSoundSpeakerPatchWrapperEqBandsBinding : public FFabricMetaSoundPatchWrapperBinding
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundSpeakerPatchWrapperEqBandsBinding")
	int32 PrimitiveDataIndex;

};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFabricMetaSoundSpeakerPatchWrapperEqBandsBinding, const TArray<FFabricMetaSoundSpeakerPatchWrapperEqBandsBinding>&, EqBands);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnMetaSoundOutputFloatChangedBatch, const FName&, OutputName, TArray<float>&, Outputs, FFabricMetaSoundPatchWrapperPeakTamer&, PeakTamer, float, DeltaSeconds);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMetaSoundOutputIntChangedBatch, const FName&, OutputName, const TArray<int32>&, Outputs);

USTRUCT()
struct FFabricConnectedInputWrapperInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bDirectlyConnected;

	UPROPERTY()
	UFabricMetaSoundPatchWrapper* Wrapper;

	UPROPERTY()
	FFabricMetaSoundNodeInfo OutputNode;

	UPROPERTY()
	FMetaSoundBuilderNodeOutputHandle ConnectedNodeOutput;

	UPROPERTY()
	FFabricMetaSoundNodeInfo InputNode;

	UPROPERTY()
	FMetaSoundBuilderNodeInputHandle CombinerNodeInput;

};

USTRUCT(BlueprintType)
struct FFabricMetaSoundDirectInputInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundDirectInputInfo")
	FName MetaSoundInputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundDirectInputInfo")
	EFabricUserOptionType InputType;

};

USTRUCT(BlueprintType)
struct FFabricMetaSoundUserOptionInputInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUserOptionInputInfo")
	FString UserOption;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUserOptionInputInfo")
	FName MetaSoundInputName;

};

USTRUCT(BlueprintType)
struct FFabricMetaSoundRuntimeInputInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundRuntimeInputInfo")
	FFabricMetaSoundUserOptionInputInfo InputInfo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundRuntimeInputInfo")
	EFabricMetasoundInputType InputType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundRuntimeInputInfo")
	EFabricUserOptionType FabricKnobType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundRuntimeInputInfo")
	FName DataType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundRuntimeInputInfo")
	FName MetaSoundInputNodeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundRuntimeInputInfo")
	bool bIsModulated;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundPatchWrapper : public UFabricModulatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void AddToManagerGraph(UFabricMetaSoundManagerComponent* Manager);

	UFUNCTION(BlueprintPure)
	TSet<FName> GetMetaSoundInputNames() const;

	UFUNCTION(BlueprintPure)
	UMusicClockComponent* GetMusicClock() const;

	UFUNCTION(BlueprintPure)
	bool GetRunsOnServer() const;

	UFUNCTION(BlueprintCallable)
	virtual void RemoveFromCurrentGraph();

	UFUNCTION(BlueprintCallable)
	void SetBoolInput(const FName& MetaSoundInputName, bool bValue);

	UFUNCTION(BlueprintCallable)
	void SetEnumInput(const FName& MetaSoundInputName, uint8 Value);

	UFUNCTION(BlueprintCallable)
	void SetFloatInput(const FName& MetaSoundInputName, float Value);

	UFUNCTION(BlueprintCallable)
	void SetIntInput(const FName& MetaSoundInputName, int32 Value);

	UFUNCTION(BlueprintCallable)
	void SetNodeEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable)
	void SetPositionalProxyActor(AActor* InLocationProxyActor);

	UFUNCTION(BlueprintCallable)
	void SetRunsOnServer(bool bAllowRunOnServer);

	UFUNCTION(BlueprintCallable)
	void SetStringInput(const FName& MetaSoundInputName, const FString& Value);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundPatchWrapper")
	FName EnabledStateInputName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundPatchWrapper")
	TSoftObjectPtr<UMetaSoundPatch> MetaSoundPatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundPatchWrapper")
	TMap<FString, FName> UserOptionsToNodeInputs;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundPatchWrapper")
	TArray<FFabricMetaSoundDirectInputInfo> DirectInputs;

	UPROPERTY(BlueprintAssignable)
	FOnMetaSoundOutputIntChangedBatch OnMetaSoundOutputIntChangedBatch;

	UPROPERTY(BlueprintAssignable)
	FOnMetaSoundOutputFloatChangedBatch OnMetaSoundOutputFloatChangedBatch;

protected:
	UFUNCTION(BlueprintNativeEvent)
	bool AddToGraphOnFirstConnect();

	UFUNCTION(BlueprintNativeEvent)
	void OnAddedToManagerGraph(UFabricMetaSoundManagerComponent* Manager);

	UFUNCTION(BlueprintNativeEvent)
	void OnMetaSoundGeneratorHandleChanged(UAudioComponent* AudioComponent, UMetasoundGeneratorHandle* GeneratorHandle);

	UFUNCTION()
	void OnMetaSoundGeneratorHandleChangedDelegate(UAudioComponent* AudioComponent, UMetasoundGeneratorHandle* GeneratorHandle);

	UFUNCTION()
	void OnMetasoundManagerEndPlay();

	UFUNCTION()
	virtual void OnMetaSoundOutputValueChanged(FName OutputName, const FMetaSoundOutput& MetaSoundOutput);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundPatchWrapper")
	FFabricMetaSoundPatchWrapperBinding SimpleSignalOutputBinding;

	UPROPERTY(BlueprintAssignable)
	FOnFabricMetaSoundPatchWrapperBindingUpdate OnSimpleSignalBindingUpdate;

	UPROPERTY(EditDefaultsOnly, Category="Perception")
	FName VisibleInputParamName;

	UPROPERTY(EditDefaultsOnly, Category="Perception")
	FName AudibleInputParamName;

	UPROPERTY(EditDefaultsOnly, Category="Perception")
	bool bCanConsumeVisibleFlag;

	UPROPERTY(EditDefaultsOnly, Category="Perception")
	bool bCanConsumeAudibleFlag;

	UPROPERTY(Transient)
	bool bIsVisible;

	UPROPERTY(Transient)
	bool bIsAudible;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FabricMetaSoundPatchWrapper", meta=(EditInline="true"))
	TObjectPtr<UFabricMetaSoundManagerComponent> CurrentManager;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundPatchWrapper")
	FFabricMetaSoundNodeInfo CurrentNode;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> PositionalProxyActor;

	UPROPERTY(Transient)
	TWeakObjectPtr<UMetasoundGeneratorHandle> CurrentGeneratorHandle;

	UPROPERTY(Transient)
	TWeakObjectPtr<UMetasoundGeneratorHandle> NewGeneratorHandle;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> CurrentAudioComponent;

	UPROPERTY(Transient, Export)
	TWeakObjectPtr<UAudioComponent> NewAudioComponent;

	UPROPERTY()
	FName CombinerMetaSoundType;

	UPROPERTY()
	FName AnalyzerMetaSoundType;

	UPROPERTY()
	TArray<FFabricMetaSoundRuntimeInputInfo> MetaSoundRuntimeInputInfos;

	UPROPERTY(Transient)
	TArray<UFabricMetaSoundPatchWrapper*> ConnectedInputWrappers;

	UPROPERTY(Transient)
	TArray<UFabricMetaSoundPatchWrapper*> PendingInputWrappers;

	UPROPERTY(Transient)
	TArray<UFabricMetaSoundPatchWrapper*> PendingOutputWrappers;

	UPROPERTY(Transient)
	TArray<FMetaSoundCombinerNodeHandle> CombinersInUse;

	UPROPERTY(Transient)
	TArray<UFabricMetaSoundPatchWrapper*> ConnectedOutputWrappers;

	UPROPERTY(Transient)
	EFabricMetaSoundPatchWrapperQuality PatchWrapperQuality;

private:
	UFUNCTION()
	void OnMetaSoundOutputChanged(FName OutputName, const FMetaSoundOutput& Output);

	UPROPERTY(Transient)
	TObjectPtr<UMetaSoundPatch> LoadedMetaSoundPatch;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundSequencerPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMidiStepSequence(UMidiStepSequence* StepSequence);

private:
	UPROPERTY(Transient)
	TObjectPtr<UMidiStepSequence> CurrentStepSequence;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundSpeakerPatchWrapper : public UFabricMetaSoundPatchWrapper
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetAudioBusFromSourceBus(USoundSourceBus* Bus);

	UPROPERTY(EditAnywhere, Category="FabricMetaSoundSpeakerPatchWrapper")
	FName SpeakerEnabledMetasoundParam;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FabricMetaSoundSpeakerPatchWrapper")
	TArray<FFabricMetaSoundSpeakerPatchWrapperEqBandsBinding> EqBands;

	UPROPERTY(BlueprintAssignable)
	FOnFabricMetaSoundSpeakerPatchWrapperEqBandsBinding OnFabricMetaSoundSpeakerPatchEqBandUpdate;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricMetaSoundTreeNode : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ConnectToChildNodes();

	UFUNCTION(BlueprintCallable)
	TArray<UFabricMetaSoundTreeNode*> GetValidChildren();

	UFUNCTION(BlueprintCallable)
	void Reset();

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundTreeNode")
	EFabricMetaSoundPinDirection PinDirection;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundTreeNode")
	UFabricMetaSoundPatchWrapper* AssociatedPatchWrapper;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundTreeNode")
	TArray<UFabricMetaSoundTreeNode*> Children;

};

