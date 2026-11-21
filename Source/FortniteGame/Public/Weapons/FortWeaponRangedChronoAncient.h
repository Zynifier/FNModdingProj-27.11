// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/TimelineComponent.h"
#include "Engine/EngineBaseTypes.h"
#include "Weapons/FortWeaponRanged.h"
#include "FortWeaponRangedChronoAncient.generated.h"

class ACustomCharacterPartModifier;
class UCurveFloat;
class UMeshComponent;
class UNiagaraComponent;
class USkeletalMeshComponentBudgeted;

USTRUCT()
struct FTimelineTickFunction : public FTickFunction
{
	GENERATED_BODY()

};

template<>
struct TStructOpsTypeTraits<FTimelineTickFunction> : public TStructOpsTypeTraitsBase2<FTimelineTickFunction>
{
	enum
	{
		WithCopy = false
	};
};

UCLASS(HideCategories=("Actor", "Input", "Components|Clothing", "Components|Base", "Components|PhysicsVolume", "Components|Activation", "Collision", "Replication", "Rendering", "Tags"))
class FORTNITEGAME_API AFortWeaponRangedChronoAncient : public AFortWeaponRanged
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	void PlayBoomerangCooldownEndedTimeline(USkeletalMeshComponentBudgeted* SkeletalMesh, UNiagaraComponent* NiagaraComponent);

	UFUNCTION(BlueprintCallable)
	void PlayBoomerangEquipTimeline(USkeletalMeshComponentBudgeted* SkeletalMesh, UNiagaraComponent* NiagaraComponent);

	UFUNCTION(BlueprintCallable)
	void PlayGauntletCatchTimeline(ACustomCharacterPartModifier* PartModifier);

	UFUNCTION(BlueprintCallable)
	void PlayGauntletEquipTimeline(ACustomCharacterPartModifier* PartModifier);

	UFUNCTION(BlueprintCallable)
	void PlayGauntletRecallTimeline(ACustomCharacterPartModifier* PartModifier);

	UFUNCTION(BlueprintCallable)
	void StopGauntletCatchTimeline();

	UFUNCTION(BlueprintCallable)
	void StopGauntletEquipTimeline();

	UFUNCTION(BlueprintCallable)
	void StopGauntletRecallTimeline();

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UMeshComponent> PlayerPawnSkeletalMeshComponent;

	UPROPERTY(Transient)
	TObjectPtr<ACustomCharacterPartModifier> GlovePartModifier;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USkeletalMeshComponentBudgeted> WeaponSkeletalMesh;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UNiagaraComponent> NiagaraAncientWeaponAmbientComponent;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponRangedChronoAncient")
	TObjectPtr<UCurveFloat> GauntletEmissiveOnEquipCurve;

	UPROPERTY(VisibleAnywhere, Category="FortWeaponRangedChronoAncient")
	FTimeline GauntletEmissiveOnEquipTimeline;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponRangedChronoAncient")
	TObjectPtr<UCurveFloat> GauntletEmissiveOnCatchCurve;

	UPROPERTY(VisibleAnywhere, Category="FortWeaponRangedChronoAncient")
	FTimeline GauntletEmissiveOnCatchTimeline;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponRangedChronoAncient")
	TObjectPtr<UCurveFloat> GauntletEmissiveOnRecallCurve;

	UPROPERTY(VisibleAnywhere, Category="FortWeaponRangedChronoAncient")
	FTimeline GauntletEmissiveOnRecallTimeline;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponRangedChronoAncient")
	TObjectPtr<UCurveFloat> BoomerangEmissiveOnEquipCurve;

	UPROPERTY(VisibleAnywhere, Category="FortWeaponRangedChronoAncient")
	FTimeline BoomerangEmissiveOnEquipTimeline;

	UPROPERTY(EditDefaultsOnly, Category="FortWeaponRangedChronoAncient")
	TObjectPtr<UCurveFloat> BoomerangEmissiveOnCooldownEndedCurve;

	UPROPERTY(VisibleAnywhere, Category="FortWeaponRangedChronoAncient")
	FTimeline BoomerangEmissiveOnCooldownEndedTimeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortWeaponRangedChronoAncient")
	float GauntletEmissiveMaxValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="FortWeaponRangedChronoAncient")
	float GauntletEmissiveGemValue;

};

