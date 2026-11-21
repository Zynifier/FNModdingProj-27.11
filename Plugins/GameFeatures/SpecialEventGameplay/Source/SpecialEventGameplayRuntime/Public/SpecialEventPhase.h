// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Info.h"
#include "GameplayTagContainer.h"
#include "SpecialEventPhase.generated.h"

class UActorComponent;
class UCameraModifier;
class UGameplayEffect;
class ULevelSequence;

UENUM(BlueprintType)
enum class ESpecialEventPhaseComponentNetModeType : uint8
{
	/** Applied to or removed from the locally controlled player on the client. */
	ClientControlled = 0,
	/** Applied to or removed from all players on the client. */
	Client = 1,
	/** Applied to or removed from all players on the server. */
	DedicatedServer = 2,
};

UENUM(BlueprintType)
enum class ESpecialEventPhaseState : uint8
{
	Unregistered = 0,
	Inactive = 1,
	Active = 2,
	Deactivated = 3,
};

USTRUCT(BlueprintType)
struct FSpecialEventPhaseComponentNetModeInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="SpecialEventPhaseComponentNetModeInfo")
	ESpecialEventPhaseComponentNetModeType NetModeType;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventPhaseComponentNetModeInfo")
	TSubclassOf<UActorComponent> ComponentClass;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Actor", "Replication", "ActorTick", "LOD", "Cooking", "Transform", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"), meta=(ChildCanTick))
class ASpecialEventPhase : public AInfo
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void DebugActivatePhase();

	UFUNCTION(BlueprintPure)
	FGameplayTag GetPhaseTag() const;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void OnPhaseFinished();

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnPhaseActivation_Client();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPhaseActivation_Server();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPhaseDeactivation_Client();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPhaseDeactivation_Server();

	UFUNCTION()
	void OnRep_PhaseState();

	UFUNCTION(BlueprintImplementableEvent)
	void PrePhaseActivation_Server();

	UFUNCTION(BlueprintCallable)
	void SetHUDElementVisibility(const FGameplayTagContainer& HUDElementTags, bool bHideElements);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="General")
	FGameplayTag PhaseTag;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventPhase")
	TSoftObjectPtr<ULevelSequence> LevelSequence;

	UPROPERTY(EditDefaultsOnly, Category="SpecialEventPhase")
	float LevelSequenceTime;

	UPROPERTY(EditDefaultsOnly, Category="Phase Activation")
	bool bApplyGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category="Phase Activation", meta=(DisplayName="Gameplay Effects to Apply on Activation", EditCondition="bApplyGameplayEffects"))
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsToApply;

	UPROPERTY(EditDefaultsOnly, Category="Phase Activation")
	TArray<FSpecialEventPhaseComponentNetModeInfo> ControllerComponentsToApplyInfoList;

	UPROPERTY(EditDefaultsOnly, Category="Phase Activation")
	TArray<FSpecialEventPhaseComponentNetModeInfo> PawnComponentsToApplyInfoList;

	UPROPERTY(EditDefaultsOnly, Category="Camera Modifiers")
	TSubclassOf<UCameraModifier> CameraModifierToApply;

	UPROPERTY(EditDefaultsOnly, Category="Camera Modifiers")
	bool bRemoveModifierOnPhaseDeactivation;

	UPROPERTY(EditDefaultsOnly, Category="Phase Deactivation")
	bool bRemoveGameplayEffects;

	UPROPERTY(EditDefaultsOnly, Category="Phase Deactivation", meta=(DisplayName="Gameplay Effects to Remove on Deactivation", EditCondition="bRemoveGameplayEffects"))
	TArray<TSubclassOf<UGameplayEffect>> GameplayEffectsToRemove;

	UPROPERTY(EditDefaultsOnly, Category="Phase Deactivation")
	TArray<FSpecialEventPhaseComponentNetModeInfo> ControllerComponentsToRemoveInfoList;

	UPROPERTY(EditDefaultsOnly, Category="Phase Deactivation")
	TArray<FSpecialEventPhaseComponentNetModeInfo> PawnComponentsToRemoveInfoList;

	UPROPERTY(BlueprintReadOnly, Category="SpecialEventPhase")
	TObjectPtr<UCameraModifier> AppliedCameraModifier;

	UPROPERTY(ReplicatedUsing=OnRep_PhaseState)
	ESpecialEventPhaseState PhaseState;

};

