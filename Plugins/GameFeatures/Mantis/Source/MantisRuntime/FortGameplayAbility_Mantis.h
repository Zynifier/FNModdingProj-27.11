// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbilityTargetTypes.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Abilities/FortGameplayAbility.h"
#include "FortMantisData.h"
#include "FortMantisTypes.h"
#include "FortGameplayAbility_Mantis.generated.h"

class AActor;
class UAbilityTask_ApplyRootMotion_Base;
class UAbilityTask_PlayMontageAndWait;
class UFortAnimNotifyState_Mantis;
class UFortAnimNotify_Mantis;
class UFortMantisPawnComponent;
enum class EFortMantisNotifyEvent : uint8;
enum class EFortMantisNotifyWindow : uint8;
enum class EFortMantisTechniqueActivationInputType : uint8;
enum class EFortMantisTechniqueActivationTimingType : uint8;
enum class EFortMantisWarpRotationMethod : uint8;
enum class EFortMantisWarpTranslationMethod : uint8;

USTRUCT()
struct FFortMantisTargetData : public FGameplayAbilityTargetData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FFortMantisRootMotionWarpInfo TechniqueWarpInfo;

	UPROPERTY()
	int32 TechniqueDataIndex;

	UPROPERTY()
	bool bIsLockedOn;

	UPROPERTY()
	FName DynamicMontageName;

	UPROPERTY()
	FFortMantisTechniqueMetadata TechniqueMetadata;

};

UCLASS()
class UFortGameplayAbility_Mantis : public UFortGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Mantis", meta=(DisplayName="OnMantisAblilityTechniqueStarted"))
	void BP_MantisAbilityTechniqueStarted(FGameplayTagContainer OwningTags, FName SequenceName, bool StartsSequence, bool EndsSequence);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Mantis", meta=(DisplayName="OnMantisInputEvent"))
	void BP_OnMantisInputEvent(const EFortMantisTechniqueActivationInputType InputType, const EFortMantisTechniqueActivationTimingType InputTiming, const bool bDidInputStartTechnique, const bool bDidInputQueueTechnique, const float InputHeldDuration);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCosmetic, Category="Mantis", meta=(DisplayName="OnMantisPreTechniqueSelection"))
	void BP_OnMantisPreTechniqueSelection();

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis", meta=(DisplayName="OnMantisTechniqueHit"))
	void BP_OnMantisTechniqueHit(const FGameplayAbilityTargetDataHandle& TargetDataHandle, FGameplayTag ApplicationTag);

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis", meta=(DisplayName="OnTechniqueNotifyEvent"))
	void BP_OnTechniqueNotifyEvent(const EFortMantisNotifyEvent NotifyEvent, const UFortAnimNotify_Mantis* Notify);

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis", meta=(DisplayName="OnTechniqueNotifyWindowEnded"))
	void BP_OnTechniqueNotifyWindowEnded(const EFortMantisNotifyWindow NotifyWindow, const UFortAnimNotifyState_Mantis* Notify);

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis", meta=(DisplayName="OnTechniqueNotifyWindowStarted"))
	void BP_OnTechniqueNotifyWindowStarted(const EFortMantisNotifyWindow NotifyWindow, const UFortAnimNotifyState_Mantis* Notify);

	UFUNCTION(BlueprintNativeEvent, Category="Mantis")
	void ConfigureRootMotionWarping(const FName TechniqueName, bool& bOutAllowTranslationWarp, bool& bOutAllowRotationWarp, AActor*& OutTargetActor, bool& bOutSnapshotTargetActorLocation, bool& bOutWarpTranslationToLocation, FVector& OutTargetLocation);

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis")
	void ConfigureRootMotionWarpingAlternativeBehavior(const FName TechniqueName, AActor*& OutTargetActor, bool& bOutSnapshotTargetActorLocation, EFortMantisWarpTranslationMethod& OutWarpTranslationMethod, FVector& OutWarpTranslationVector, EFortMantisWarpRotationMethod& OutWarpRotationMethod, FRotator& OutStaticRotation);

	UFUNCTION(BlueprintImplementableEvent, Category="Mantis")
	void FillMetadataForTechnique(const FName TechniqueName, FFortMantisTechniqueMetadata& OutTechniqueMetadata);

	UFUNCTION(BlueprintNativeEvent, Category="Mantis")
	FName GetDynamicMontageNameForTechnique(const FName TechniqueName) const;

	UFUNCTION(BlueprintNativeEvent, Category="Mantis")
	int32 GetLevelForGameplayEffectContainer(const FGameplayTag ApplicationTag) const;

	UFUNCTION()
	void OnMontageCancelled();

	UFUNCTION()
	void OnMontageFinished();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mantis")
	bool bAllowRootMotionWarping;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mantis")
	bool bUseAlternativeWarpingBehavior;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mantis")
	bool bApplyEffectContainerOnTechniqueDamage;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Mantis")
	bool bApplyEffectContainerOnTechniqueStart;

	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMantisPawnComponent> MantisPawnComponent;

	UPROPERTY()
	TObjectPtr<UAbilityTask_PlayMontageAndWait> MontageTask;

	UPROPERTY()
	TObjectPtr<UAbilityTask_ApplyRootMotion_Base> RootMotionTask;

};

