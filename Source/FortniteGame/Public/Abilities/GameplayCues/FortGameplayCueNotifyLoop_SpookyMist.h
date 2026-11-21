// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "FortGameplayCueNotifyLoop_SpookyMist.generated.h"

class UMaterialParameterCollection;
class UParticleSystemComponent;
class UPostProcessComponent;
class USkeletalMeshComponent;
class USoundBase;
class UTimelineComponent;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AFortGameplayCueNotifyLoop_SpookyMist : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void BeginExpireTell();

	UFUNCTION()
	void ClearExpireTell();

	UFUNCTION()
	void ExpireWarningTick();

	UPROPERTY(BlueprintReadWrite, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float InteractVisibility;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	int32 HeadFXComponentIndex;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	int32 BodyFXComponentIndex;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	TObjectPtr<UMaterialParameterCollection> MaterialParameterCollection;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FName RibbonsFXParameterName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FName FriendlyFXParameterName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FName SpookyMistModeMatParameterName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FName MovementOpacityMatParameterName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FName VelocityAudioParameterName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FName FlashStartTimeMatParameterName;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float SpeedRibbonVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float WalkVisibilityVelocityThreshold;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float VisibilityLevelInterpSpeed;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FScalableFloat WalkVizMultiplier;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FScalableFloat SprintVizMultiplier;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FScalableFloat FriendlyVizMultiplier;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FScalableFloat ShadowPlaneOpacity;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FScalableFloat Duration;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	FScalableFloat TellDuration;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	TObjectPtr<USoundBase> ExpirationSound;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float ExpirationSoundPeriod;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float AudioVelocityInterpSpeed;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float MinAudioRange;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	float MaxAudioRange;

	UPROPERTY(EditAnywhere, Category="FortGameplayCueNotifyLoop_SpookyMist")
	bool bShowExpireTell;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UPostProcessComponent> PostProcessComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UTimelineComponent> InteractionTimelineComponent;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> HeadFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UParticleSystemComponent> BodyFX;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<USkeletalMeshComponent>> PlayerSkeletalMeshes;

};

