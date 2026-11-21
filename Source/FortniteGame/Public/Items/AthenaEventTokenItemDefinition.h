// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItemDefinition.h"
#include "AthenaEventTokenItemDefinition.generated.h"

UENUM()
enum class EEventTokenType : uint8
{
	Invite = 0,
	Creation = 1,
};

UCLASS(BlueprintType)
class UAthenaEventTokenItemDefinition : public UFortAccountItemDefinition
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaEventTokenItemDefinition")
	EEventTokenType TokenType;

};

