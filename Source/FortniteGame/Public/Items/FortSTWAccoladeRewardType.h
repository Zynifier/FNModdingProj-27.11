// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortTokenType.h"
#include "FortSTWAccoladeRewardType.generated.h"

class UStWFortAccoladeItemDefinition;

UENUM(BlueprintType)
enum class EFortAccoladeSource : uint8
{
	Mission = 0,
	Quest = 1,
};

UCLASS(MinimalAPI)
class UFortSTWAccoladeRewardType : public UFortTokenType
{
	GENERATED_BODY()

private:
	UPROPERTY(EditDefaultsOnly, Category="FortSTWAccoladeRewardType")
	TObjectPtr<UStWFortAccoladeItemDefinition> AccoladeToGrant;

	UPROPERTY(EditDefaultsOnly, Category="FortSTWAccoladeRewardType")
	EFortAccoladeSource AccoladeSource;

};

