// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "Items/FortItemProfileTypes.h"
#include "FortCodeTokenItemDefinition.generated.h"

UENUM()
enum class ECodeTokenPlatform : uint8
{
	PC = 0,
	PS4 = 1,
	XBOX = 2,
};

UCLASS(BlueprintType)
class UFortCodeTokenItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCodeTokenItemDefinition")
	FString RedemptionCodeRule;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCodeTokenItemDefinition")
	FString RedemptionCodeGroup;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCodeTokenItemDefinition")
	TArray<ECodeTokenPlatform> AllowedPlatforms;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCodeTokenItemDefinition")
	EItemProfileType ProfileType;

};

