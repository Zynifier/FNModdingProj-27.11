// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "FortBotBuildingContainerBlacklistDataTable.generated.h"

class ABuildingContainer;

USTRUCT()
struct FFortBotBuildingContainerBlacklistDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Building Container")
	TSoftClassPtr<ABuildingContainer> BlacklistedActorClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Building Container")
	bool bIsBlacklisted;

};

