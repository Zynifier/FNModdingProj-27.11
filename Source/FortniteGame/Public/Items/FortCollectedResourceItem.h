// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Items/FortAccountItem.h"
#include "FortCollectedResourceItem.generated.h"

class UFortItemDefinition;

UCLASS()
class UFortCollectedResourceItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UPROPERTY()
	double stored_value;

	UPROPERTY()
	FString last_updated;

	UPROPERTY()
	TObjectPtr<UFortItemDefinition> PayoutResource;

};

