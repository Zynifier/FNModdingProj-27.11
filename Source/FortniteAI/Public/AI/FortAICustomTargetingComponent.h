// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Math/MathFwd.h"
#include "FortAICustomTargetingComponent.generated.h"

UENUM(meta=(Bitflags, UseEnumValuesAsMaskValuesInEditor="true"))
enum class EAICustomTargetRequestType : uint8
{
	Movement = 1,
	MeleeAttack = 2,
	RangedAttack = 4,
};

USTRUCT()
struct FAICustomTargetConfiguration
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AICustomTargetConfiguration")
	FVector Offset;

	UPROPERTY(EditAnywhere, Category="AICustomTargetConfiguration", meta=(Bitmask, BitmaskEnum="/Script/FortniteAI.EAICustomTargetRequestType"))
	uint8 ValidRequestTypes;

};

UCLASS(Config=Game, MinimalAPI, ClassGroup=("AI"), meta=(BlueprintSpawnableComponent))
class UFortAICustomTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="AI")
	TArray<FAICustomTargetConfiguration> Configurations;

};

