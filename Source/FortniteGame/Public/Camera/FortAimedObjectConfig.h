// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/MathFwd.h"
#include "FortAimedObjectConfig.generated.h"

class UAnimInstance;

UENUM()
enum class EAimedObjectType : uint8
{
	HasSightOrScope = 0,
	HighlyAnimated = 1,
};

USTRUCT(BlueprintType)
struct FFortAimedObjectConfig
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	FVector CameraOffset;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	FRotator CameraSpaceRotationOffset;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	EAimedObjectType ObjectType;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	float BlendRate;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	float HidePawnBlendInWeight;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	float HidePawnBlendOutWeight;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	FName AimedObjectBoneName;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	FName CameraBoneName;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	FName HeadBoneName;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	FName AimedObjectHandleBoneName;

	UPROPERTY(EditAnywhere, Category="FortAimedObjectConfig")
	TSubclassOf<UAnimInstance> PostProcessAnimation;

};

