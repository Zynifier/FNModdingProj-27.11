// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "BlueprintContextBase.h"
#include "FortAccountStatsContext.generated.h"

UCLASS()
class FORTNITEUI_API UFortAccountStatsContext : public UBlueprintContextBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="AccountStats")
	bool CanShowAccountStats() const;

};

