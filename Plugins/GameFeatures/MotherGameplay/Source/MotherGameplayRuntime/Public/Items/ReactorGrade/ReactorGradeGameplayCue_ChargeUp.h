// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Math/MathFwd.h"
#include "ScalableFloat.h"
#include "Abilities/FortGameplayCueNotify_Loop.h"
#include "ReactorGradeGameplayCue_ChargeUp.generated.h"

class AFortPawn;
class UFortWeaponFxComponent_ChargeAimLocation;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Tick", "Rendering", "Input", "Actor", "Replication"))
class AReactorGradeGameplayCue_ChargeUp : public AFortGameplayCueNotify_Loop
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const FVector& GetFoundEndPoint() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnEndPointUpdated(const FVector& FoundPoint);

	UFUNCTION(BlueprintCallable)
	void UpdateAimEndPoint();

protected:
	UPROPERTY(BlueprintReadWrite, Category="ReactorGradeGameplayCue_ChargeUp")
	TObjectPtr<AFortPawn> Pawn;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UFortWeaponFxComponent_ChargeAimLocation> CachedAimLocationComponent;

	UPROPERTY(BlueprintReadOnly, Category="ReactorGradeGameplayCue_ChargeUp")
	FVector FoundEndPoint;

	UPROPERTY(EditDefaultsOnly, Category="ReactorGradeGameplayCue_ChargeUp")
	FScalableFloat MinHitDistance;

	UPROPERTY(EditDefaultsOnly, Category="ReactorGradeGameplayCue_ChargeUp")
	FScalableFloat HitObjectsLimit;

	UPROPERTY(EditDefaultsOnly, Category="ReactorGradeGameplayCue_ChargeUp")
	TEnumAsByte<ECollisionChannel> TraceChannel;

};

