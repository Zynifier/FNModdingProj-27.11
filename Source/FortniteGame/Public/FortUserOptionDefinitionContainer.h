// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/CurveTable.h"
#include "FortUserOptionDefinitions.h"
#include "FortUserOptionDefinitionContainer.generated.h"

USTRUCT(BlueprintType)
struct FUserOptionDefinitionContainer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter))
	FText DisplayName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter))
	FText Description;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter))
	FText InteractionText;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter))
	FCurveTableRowHandle InteractionSpeed;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter))
	bool bRecurseBaseClassesForUserOptions;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter))
	bool bPreserveInheritedUserOptionOrdering;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="UserOptions|Config", meta=(NoGetter, TitleProperty="DisplayName"))
	TArray<FUserOptionDefinition> Definitions;

};

