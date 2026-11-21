// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FMInWorldKnobInterface.h"
#include "FabricInteractableInterface.h"
#include "FabricModulatorInterface.h"
#include "FMInWorldKnobActorBase.generated.h"

class AFMInWorldKnobActorBase;
class APlayerController;
class UFMDeviceCableModulatorPortComponent;
class UFabricFloatProviderBase;
class UFabricInteractableViewModel;
class UObject;
class UPlaylistUserOptionBase;
class USceneComponent;
class UUserWidget;

UCLASS(Transient, BlueprintType, ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMINWORLDKNOBSRUNTIME_API AFMInWorldKnobActorBase : public AActor, public IInWorldKnobInterface, public IFabricInteractable, public IFabricModulator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CopyAttributesFromOtherKnob(AFMInWorldKnobActorBase* OtherKnob);

	UFUNCTION(BlueprintPure)
	bool GetConsumeInteractionFromChildInteractable(APlayerController* PlayerController) const;

	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="Get Copy Class"))
	UClass* GetCopyClassInternal() const;

	UFUNCTION(BlueprintNativeEvent, meta=(Displayname="Get Copy Widget Class"))
	TSubclassOf<UUserWidget> GetCopyWidgetClassInternal() const;

	UFUNCTION(BlueprintPure)
	bool GetCurrentValueAsBool() const;

	UFUNCTION(BlueprintPure)
	uint8 GetCurrentValueAsEnum() const;

	UFUNCTION(BlueprintPure)
	float GetCurrentValueAsFloat() const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrentValueAsInt() const;

	UFUNCTION(BlueprintPure)
	FName GetCurrentValueAsName() const;

	UFUNCTION(BlueprintPure)
	FString GetCurrentValueAsString() const;

	UFUNCTION(BlueprintPure)
	APlayerController* GetInteractingController() const;

	UFUNCTION(BlueprintPure)
	UFabricInteractableViewModel* GetWidgetViewModel() const;

	UFUNCTION(BlueprintPure)
	bool HasActiveFloatProvider() const;

	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnWidgetViewModelSet"))
	void ReceiveOnWidgetViewModelSet();

	UFUNCTION(BlueprintCallable)
	void ResetToDefaultValue(APlayerController* PlayerController);

	UFUNCTION(BlueprintCallable)
	void SetKnobDisplayOnly(bool bDisplayOnly);

	UFUNCTION(BlueprintCallable)
	void SetKnobEnabled(bool bEnabled);

	UFUNCTION(BlueprintCallable)
	void SetWidgetViewModel(UFabricInteractableViewModel* ViewModel);

	UPROPERTY(BlueprintAssignable)
	FOnModulatedPropertyValueChanged OnModulatedPropertyValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnInWorldKnobRuntimeValueChanged OnKnobRuntimeValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnInWorldKnobSerializedValueChanged OnKnobSerializedValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnFloatProviderConnectionChanged OnFloatProviderConnectionChanged;

protected:
	UFUNCTION(BlueprintNativeEvent, meta=(DisplayName="Copy Attributes From Knob"))
	void CopyAttributesFromOtherKnobInternal(AFMInWorldKnobActorBase* OtherKnob);

	UFUNCTION(BlueprintPure)
	int32 GetCurrentOptionIndex() const;

	UFUNCTION(BlueprintPure)
	FText GetCurrentValueLabel();

	UFUNCTION(BlueprintPure)
	USceneComponent* GetHitComponent() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumberOptions() const;

	UFUNCTION(BlueprintImplementableEvent)
	void HitComponentUpdated(USceneComponent* NewHitComponent);

	UFUNCTION(BlueprintPure)
	bool IsOverriddenByPort() const;

	UFUNCTION(BlueprintCallable)
	void KnobValueChanged(int32 NewIndex, bool SnapToSelection, APlayerController* PlayerController);

	UFUNCTION()
	void OnKnobIsVisible(bool bInIsVisible);

	UFUNCTION(BlueprintNativeEvent)
	void SetCurrentKnobPosition(float KnobPosition);

	UFUNCTION(BlueprintNativeEvent)
	void SetNumberOptions(int32 NumberOptions);

	UFUNCTION(BlueprintNativeEvent)
	void SetSelectedIndex(int32 Index, bool SnapToSelection);

	UFUNCTION(BlueprintNativeEvent)
	void SetTitle(const FText& Title);

	UFUNCTION(BlueprintImplementableEvent)
	void StartTrackingInput(APlayerController* PlayerController);

	UFUNCTION(BlueprintImplementableEvent)
	void StopTrackingInput();

	UFUNCTION(BlueprintNativeEvent)
	void UpdateDisplayOnlyVisuals(bool bDisplayOnly);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateEnabledVisuals(bool bEnabled);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateFocusVisuals(bool bFocused);

	UFUNCTION(BlueprintNativeEvent)
	void UpdateInteractableVisuals(bool bInteractable);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorBase")
	FString OptionKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorBase")
	FText OverriddenTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorBase")
	bool bCanBeModulated;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorBase")
	bool bKnobEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorBase")
	bool bKnobDisplayOnly;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Export, Category="FMInWorldKnobActorBase", meta=(EditInline="true"))
	TObjectPtr<USceneComponent> ModulatorPortParent;

	UPROPERTY(BlueprintReadOnly, Transient, Export, Category="FMInWorldKnobActorBase", meta=(EditInline="true"))
	TObjectPtr<UFMDeviceCableModulatorPortComponent> ModulatorPort;

private:
	UFUNCTION()
	void OnFloatProviderFloatUpdated(float NewFloat);

	UFUNCTION()
	void OnReceiveFloatProvidersFromPort(const TArray<UFabricFloatProviderBase*>& FloatProvider);

	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptionBase> MyUserOption;

	UPROPERTY(Transient)
	TArray<TWeakObjectPtr<UFabricFloatProviderBase>> CurrentFloatProviders;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFabricFloatProviderBase> ActiveFloatProvider;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> HitComponent;

	UPROPERTY(Transient)
	TWeakObjectPtr<APlayerController> InteractingController;

	UPROPERTY(Transient)
	EFabricInteractableType InteractableType;

	UPROPERTY(Transient)
	TWeakObjectPtr<UFabricInteractableViewModel> WidgetViewModel;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FMInWorldKnobActorBase", meta=(AllowPrivateAccess="true"))
	TArray<FText> OptionLabels;

	UPROPERTY(EditDefaultsOnly, AdvancedDisplay, Category="FMInWorldKnobActorBase", meta=(AllowPrivateAccess="true"))
	TArray<FString> OptionValues;

	UPROPERTY(Transient)
	int32 SerializedOptionIndex;

	UPROPERTY(Transient)
	int32 CurrentOptionIndex;

	UPROPERTY(Transient)
	float ClampedKnobValue;

	UPROPERTY(Transient)
	bool bTrackingInput;

	UPROPERTY(Transient)
	bool bIsVisibilityBound;

};

