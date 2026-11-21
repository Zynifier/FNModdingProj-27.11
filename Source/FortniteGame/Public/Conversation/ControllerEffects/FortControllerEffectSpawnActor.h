// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "Conversation/ControllerEffects/FortControllerEffect.h"
#include "Conversation/FortWeightedActorClassList.h"
#include "FortControllerEffectSpawnActor.generated.h"

class AActor;

UCLASS(meta=(DisplayName="Effect: Spawn Actor"))
class UFortControllerEffect_SpawnActor : public UFortControllerEffect
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor")
	bool bUseWeightedActorList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor", meta=(editCondition="!bUseWeightedActorList"))
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Actor", meta=(editCondition="!bUseWeightedActorList"))
	FFortWeightedActorTypeList WeightedActorClassList;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Config")
	float SpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Location")
	bool bSpawnRelativeToServiceProvider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Location")
	FVector LocalSpaceSpawnOffset;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Location")
	bool bLocalSpaceOffsetIgnorePitchAndRoll;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Location")
	FRotator AdditionalRelativeRotationOffset;

};

