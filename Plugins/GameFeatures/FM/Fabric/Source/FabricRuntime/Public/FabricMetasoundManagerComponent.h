// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MetasoundBuilderSubsystem.h"
#include "FabricSignificance.h"
#include "HarmonixMidi/BarMap.h"
#include "FabricMetasoundManagerComponent.generated.h"

class AActor;
class ABuildingActor;
class UAudioComponent;
class UFabricMetaSoundPatchWrapper;
class UFabricSignificanceAsset;
class UMetaSoundPatch;
class UMetaSoundSourceBuilder;
class UMetasoundGeneratorHandle;
class UMetasoundOfflinePlayerComponent;
class UMetasoundParameterPack;
class UMusicClockComponent;
enum class EFabricMetasoundPlayState : uint8;
enum class EFabricUserOptionType : uint8;
enum class EMusicKey : uint8;
enum class EMusicKeyMode : uint8;

UENUM(BlueprintType)
enum class EFabricMetasoundPlayState : uint8
{
	Playing = 0,
	Rebuilding = 1,
	Paused = 2,
	Stopped = 3,
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMetasoundGeneratorCrossfadeStarted, float, CrossfadeSeconds);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMetasoundGeneratorHandleChanged, UAudioComponent*, AudioComponent, UMetasoundGeneratorHandle*, GeneratorHandle);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnMetasoundManagerEndPlaySignature);

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricMetaSoundUtilityParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityParams")
	FName SwitcherEnabledParam;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityParams")
	FName SelectEnabledParam;

};

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricLoadedUtilityPatches
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricLoadedUtilityPatches")
	TObjectPtr<UMetaSoundPatch> CombinerNode;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricLoadedUtilityPatches")
	TObjectPtr<UMetaSoundPatch> SwitcherNode;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricLoadedUtilityPatches")
	TObjectPtr<UMetaSoundPatch> SelectNode;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricLoadedUtilityPatches")
	TObjectPtr<UMetaSoundPatch> AnalyzerNode;

	UPROPERTY(BlueprintReadWrite, Category="FabricLoadedUtilityPatches")
	FFabricMetaSoundUtilityParams UtilityNodeParams;

};

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricMetaSoundNodeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FMetaSoundNodeHandle NodeHandle;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FMetaSoundNodeHandle OutputConnectionHandle;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FMetaSoundNodeHandle InputConnectionHandle;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FName Name;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	TMap<FName, FMetaSoundBuilderNodeOutputHandle> InputNodeNamesToHandles;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FMetaSoundNodeHandle AnalyzerHandle;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricMetaSoundNodeInfo")
	TObjectPtr<UMetasoundParameterPack> AnalyzerParameterPack;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FName AnalyzerName;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FMetaSoundNodeHandle SwitcherHandle;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FMetaSoundNodeHandle SelectHandle;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FName NodeEnabledInput;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	FName AnalyzerNodeVisibleInput;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodeInfo")
	TArray<FName> AnalyzerOutputNames;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricMetaSoundNodeInfo")
	TObjectPtr<UMetaSoundPatch> PatchSpawnedFrom;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricMetaSoundNodeInfo")
	TObjectPtr<UMetasoundParameterPack> ParameterPack;

};

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricMetaSoundNodePool
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodePool")
	int32 NumberAdded;

	UPROPERTY(BlueprintReadWrite, Category="FabricMetaSoundNodePool")
	TArray<FFabricMetaSoundNodeInfo> FreeNodes;

	UPROPERTY(BlueprintReadWrite, Transient, Category="FabricMetaSoundNodePool")
	TObjectPtr<UMetaSoundPatch> PatchSpawnedFrom;

};

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricMetaSoundUtilityPatches
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityPatches")
	TSoftObjectPtr<UMetaSoundPatch> CombinerNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityPatches")
	TSoftObjectPtr<UMetaSoundPatch> SwitcherNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityPatches")
	TSoftObjectPtr<UMetaSoundPatch> SelectNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityPatches")
	TSoftObjectPtr<UMetaSoundPatch> AnalyzerNode;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundUtilityPatches")
	FFabricMetaSoundUtilityParams UtilityNodeParams;

};

USTRUCT()
struct FABRICRUNTIME_API FMetaSoundCombinerNodeHandle
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFabricMetaSoundNodeInfo NodeInfo;

	UPROPERTY()
	FMetaSoundBuilderNodeInputHandle CombinerInput1;

	UPROPERTY()
	FMetaSoundBuilderNodeInputHandle CombinerInput2;

	UPROPERTY()
	FMetaSoundBuilderNodeOutputHandle CombinedOutput;

};

UCLASS(BlueprintType, Blueprintable, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FABRICRUNTIME_API UFabricMetaSoundManagerComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, meta=(DisplayName="Add Input Node For Node"))
	void AddInputNodeForNodeByNameBP(UPARAM(ref) FFabricMetaSoundNodeInfo& InOutNode, EFabricUserOptionType UserOptionType, const FName& InputName);

	UFUNCTION(BlueprintCallable)
	void AddOutputNodeForOutputVertex(const FMetaSoundBuilderNodeOutputHandle& OutputVertex, const FName& NodeName, FName& OutOutputName, EMetaSoundBuilderResult& Result);

	UFUNCTION(BlueprintPure)
	bool AreAllPatchesReady() const;

	UFUNCTION(BlueprintCallable)
	void FreeMetaSoundNode(const FFabricMetaSoundNodeInfo& Node);

	UFUNCTION(BlueprintPure)
	UMetaSoundSourceBuilder* GetBuilder() const;

	UFUNCTION(BlueprintPure)
	UMetasoundGeneratorHandle* GetMetasoundGeneratorHandle() const;

	UFUNCTION(BlueprintPure)
	static FName GetMetasoundInputNodeName(FName NodeName, FName InputName);

	UFUNCTION(BlueprintCallable)
	FFabricMetaSoundNodeInfo GetMetaSoundNodeForWrapper(UFabricMetaSoundPatchWrapper* PatchWrapper);

	UFUNCTION(BlueprintPure)
	UMusicClockComponent* GetMusicClock() const;

	UFUNCTION(BlueprintCallable)
	void InvalidateMetasoundGeneratorHandle();

	UFUNCTION(BlueprintCallable)
	void NotifyGraphChanged();

	UFUNCTION(BlueprintCallable)
	void PauseMetasound();

	UFUNCTION(BlueprintCallable)
	void PlayMetasound(ABuildingActor* InStartMetasoundLockDevice);

	UFUNCTION(BlueprintCallable)
	void RegisterAsAudible(AActor* Device);

	UFUNCTION()
	void SeekToMs(float Ms);

	UFUNCTION()
	void SeekToTimestamp(const FMusicTimestamp& Timestamp);

	UFUNCTION(BlueprintCallable)
	void SetAudioComponents(TArray<UAudioComponent*> AudioComponents);

	UFUNCTION(BlueprintCallable)
	void SetMetasoundGeneratorHandle(UAudioComponent* AudioComponent, UMetasoundGeneratorHandle* GeneratorHandle);

	UFUNCTION(BlueprintCallable)
	void SetMusicClock(UMusicClockComponent* MusicClockComponent);

	UFUNCTION(BlueprintCallable)
	void SetMusicKey(EMusicKey Key, EMusicKeyMode Mode);

	UFUNCTION(BlueprintCallable)
	void SetSpeed(float Speed);

	UFUNCTION(BlueprintCallable)
	void SetTempo(float Tempo);

	UFUNCTION(BlueprintCallable)
	void SetTimeSignature(int32 Numerator, int32 Denominator);

	UFUNCTION(BlueprintCallable)
	void StopMetasound(ABuildingActor* InStartMetasoundLockDevice);

	UFUNCTION(BlueprintCallable)
	void UnregisterAsAudible(AActor* Device);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	TSoftObjectPtr<UMetaSoundPatch> HarmonixMusicProviderPatch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FFabricMetaSoundUtilityPatches MidiStreamUtilityPatches;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FFabricMetaSoundUtilityPatches AudioUtilityPatches;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderVolumeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderPlayTriggerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderRestartTriggerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderSeekTriggerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderPauseTriggerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderContinueTriggerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderStopTriggerName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderTempoName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderSpeedName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderRootNoteName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderScaleName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderSeekTargetName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderTimeSigNumName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	FName MusicProviderTimeSigDenomName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	float CrossfadeSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FabricMetaSoundManagerComponent")
	float RebuildTimeOutSeconds;

	UPROPERTY(BlueprintAssignable)
	FMetasoundGeneratorHandleChanged OnMetasoundGeneratorHandleChanged;

	UPROPERTY(BlueprintAssignable)
	FMetasoundGeneratorCrossfadeStarted OnMetasoundGeneratorCrossfadeStarted;

protected:
	UFUNCTION(BlueprintPure)
	EFabricMetasoundPlayState GetCurrentPlaystate() const;

	UPROPERTY(EditDefaultsOnly, Category="FabricMetaSoundManagerComponent")
	TArray<FFabricSignificanceBasedUpdateBucketRuntime> SignificanceRuntimeBuckets;

	UPROPERTY(EditDefaultsOnly, Category="FabricMetaSoundManagerComponent")
	TObjectPtr<UFabricSignificanceAsset> SignificanceBasedUpdate;

	UPROPERTY(EditDefaultsOnly, Category="FabricMetaSoundManagerComponent")
	float InitialCooldownTimeInSeconds;

	UPROPERTY(BlueprintReadOnly, Replicated, Category="FabricMetaSoundManagerComponent")
	float ReplicatedReceivedSignalBufferDuration;

private:
	UFUNCTION()
	void OnGeneratorJustStarted(int32 ComponentIndex);

	UFUNCTION()
	void OnMetasoundAuditionGeneratorHandleCreated(UMetasoundGeneratorHandle* GeneratorHandle);

	UPROPERTY(Transient)
	TObjectPtr<UMetaSoundSourceBuilder> SourceBuilder;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMusicClockComponent> MusicClock;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UAudioComponent*> PlaybackAudioComponents;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<UMetasoundOfflinePlayerComponent*> ServerPlaybackComponents;

	UPROPERTY(Transient)
	TObjectPtr<UMetasoundGeneratorHandle> CurrentGeneratorHandle;

	UPROPERTY(Transient)
	TObjectPtr<UMetasoundGeneratorHandle> OldGeneratorHandle;

	UPROPERTY(Transient)
	TObjectPtr<UMetasoundGeneratorHandle> NewGeneratorHandle;

	UPROPERTY(Transient)
	TWeakObjectPtr<ABuildingActor> StartMetasoundLockDevice;

	UPROPERTY(Transient)
	FFabricMetaSoundNodeInfo HarmonixMusicProviderNode;

	UPROPERTY(Transient)
	FMetaSoundBuilderNodeOutputHandle OnPlayNodeOutput;

	UPROPERTY(Transient)
	FMetaSoundBuilderNodeInputHandle OnFinishedNodeInput;

	UPROPERTY(Transient)
	TArray<FMetaSoundBuilderNodeInputHandle> AudioOutNodeInputs;

	UPROPERTY(Transient)
	TMap<UMetaSoundPatch*, FFabricMetaSoundNodePool> FreeMetaSoundNodes;

	UPROPERTY(Transient)
	TMap<FName, FFabricLoadedUtilityPatches> UtilityNodeTypesToPatches;

	UPROPERTY(Transient)
	bool bGraphDirty;

	UPROPERTY(Transient)
	bool bIsAudioless;

	UPROPERTY(Transient)
	bool bHasCompletedInitialCooldown;

};

