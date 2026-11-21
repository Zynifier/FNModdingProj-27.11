// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "Engine/HitResult.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "FortPlacementActorTagTest.generated.h"

class AActor;
class AFortPlacementActor;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Input", "Actor", "Replication", "Rendering"))
class UFortPlacementActorTagTest : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="PlacementTagTests", meta=(AutoCreateRefTerm="ActorsToIgnore", bIgnoreSelf="true", Keywords="raycast"))
	bool LineTraceByChannel(AFortPlacementActor* PlacementActor, const FVector Start, const FVector End, ETraceTypeQuery TraceChannel, bool bTraceComplex, const TArray<AActor*>& ActorsToIgnore, FHitResult& OutHit, bool bIgnoreSelf) const;

	UFUNCTION(BlueprintNativeEvent, Category="PlacementTagTests")
	bool ShouldApplyTagsToPlacementActor(AFortPlacementActor* FocusPlacementActor, const FVector& AveragePlacementActorLocation) const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPlacementActorTagTest")
	FGameplayTagContainer TagsToApplyOnSuccess;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortPlacementActorTagTest")
	FGameplayTagContainer TagsToApplyOnFailure;

};

