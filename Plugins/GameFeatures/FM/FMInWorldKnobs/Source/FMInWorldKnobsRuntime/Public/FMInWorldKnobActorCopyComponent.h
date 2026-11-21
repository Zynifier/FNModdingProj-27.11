// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FMInWorldKnobInterface.h"
#include "FabricChildActorComponent.h"
#include "FabricInteractableInterface.h"
#include "FabricModulatorInterface.h"
#include "FMInWorldKnobActorCopyComponent.generated.h"

class AFMInWorldKnobActorBase;
class APlayerController;
class UFMInWorldKnobActorCopyComponent;
class UObject;
class UPlaylistUserOptionBase;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnKnobActorSet, UFMInWorldKnobActorCopyComponent*, CopyComponent, AFMInWorldKnobActorBase*, NewKnobActor);

UCLASS(BlueprintType, HideCategories=("Object", "LOD", "Physics", "Lighting", "TextureStreaming", "Activation", "Components|Activation", "Collision", "Trigger", "PhysicsVolume"), ClassGroup=("Harmonix"), meta=(BlueprintSpawnableComponent))
class FMINWORLDKNOBSRUNTIME_API UFMInWorldKnobActorCopyComponent : public UFabricChildActorComponent, public IInWorldKnobInterface, public IFabricInteractable, public IFabricModulator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void ClearCopiedInWorldKnob();

	UFUNCTION(BlueprintPure, meta=(DisplayName="Get Current Knob Value"))
	FString GetCurrentKnobValueBP() const;

	UFUNCTION(BlueprintCallable)
	void SetCopiedInWorldKnob(UObject* InWorldKnobObject);

	UPROPERTY(BlueprintAssignable)
	FOnModulatedPropertyValueChanged OnModulatedPropertyValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnInWorldKnobRuntimeValueChanged OnKnobRuntimeValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnInWorldKnobSerializedValueChanged OnKnobSerializedValueChanged;

	UPROPERTY(BlueprintAssignable)
	FOnFloatProviderConnectionChanged OnFloatProviderConnectionChanged;

	UPROPERTY(BlueprintAssignable)
	FOnKnobActorSet OnKnobActorSet;

protected:
	UPROPERTY(EditAnywhere, Category="FMInWorldKnobActorCopyComponent")
	TSubclassOf<AFMInWorldKnobActorBase> DefaultKnobActorClass;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FMInWorldKnobActorCopyComponent")
	TObjectPtr<AFMInWorldKnobActorBase> InWorldKnobActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorCopyComponent")
	FString OptionKey;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorCopyComponent")
	FText OverriddenTitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorCopyComponent")
	bool bCanBeModulated;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FMInWorldKnobActorCopyComponent")
	bool bKnobEnabled;

private:
	UFUNCTION()
	void OnInWorldKnobFloatProviderConnectionChanged(bool bConnected, UObject* ModulatorObject);

	UFUNCTION()
	void OnInWorldKnobModulatedPropertyValueChanged(const FString& Value, UObject* ModulatorObject);

	UFUNCTION()
	void OnInWorldKnobRuntimeValueChanged(const FString& Value, UPlaylistUserOptionBase* Option);

	UFUNCTION()
	void OnInWorldKnobSerializedValueChanged(const FString& Value, UPlaylistUserOptionBase* Option, APlayerController* PlayerController);

	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptionBase> OuterUserOption;

	UPROPERTY(Transient)
	TObjectPtr<UPlaylistUserOptionBase> CopiedUserOption;

};

