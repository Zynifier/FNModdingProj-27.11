// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/TopBar/AthenaTopBar.h"
#include "FortUIRequestTypes.generated.h"

class UWidget;

USTRUCT(BlueprintType)
struct FExternalDynamicTabParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ExternalDynamicTabParams")
	TSoftClassPtr<UWidget> TabScreenClass;

	UPROPERTY(EditAnywhere, Category="ExternalDynamicTabParams")
	FFortTopBarTabButtonInfo TabButtonInfo;

	UPROPERTY(EditAnywhere, Category="ExternalDynamicTabParams")
	bool bIsMobileOverride;

};

USTRUCT()
struct FFrontendDisabledTabs
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FrontendDisabledTabs")
	TArray<FName> DisabledTabNames;

	UPROPERTY(EditAnywhere, Category="FrontendDisabledTabs")
	TArray<FName> HiddenTabNames;

};

