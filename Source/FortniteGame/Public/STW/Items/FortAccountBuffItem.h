// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/DateTime.h"
#include "Items/FortAccountItem.h"
#include "FortAccountBuffItem.generated.h"

UCLASS()
class UFortAccountBuffItem : public UFortAccountItem
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool IsActive() const;

	UPROPERTY(BlueprintReadOnly, Category="FortAccountBuffItem")
	FDateTime expiration_date;

};

