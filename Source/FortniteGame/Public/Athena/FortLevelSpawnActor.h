// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "Styling/SlateBrush.h"
#include "FortLevelSpawnActor.generated.h"

UCLASS(Abstract, MinimalAPI, BlueprintType, Blueprintable)
class AFortLevelSpawnActor : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FName SpecialActorUniqueID;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FGameplayTag SpecialActorCategoryTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FSlateBrush MinimapIconBrush;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="SpecialActor")
	FVector2D MinimapIconScale;

protected:
	UPROPERTY(Transient)
	int32 CachedSpecialActorIdx;

	UPROPERTY(Transient, Replicated)
	FName SpecialActorID;

};

