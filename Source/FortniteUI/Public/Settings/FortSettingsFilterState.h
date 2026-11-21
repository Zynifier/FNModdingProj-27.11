// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortSettingsFilterState.generated.h"

class UFortSetting;

USTRUCT()
struct FFortSettingsFilterState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	bool bIncludeDisabled;

	UPROPERTY()
	bool bIncludeHidden;

	UPROPERTY()
	bool bIncludeResetable;

	UPROPERTY()
	bool bIncludeNestedPages;

private:
	UPROPERTY()
	TArray<TObjectPtr<UFortSetting>> SettingRootList;

	UPROPERTY()
	TArray<TObjectPtr<UFortSetting>> SettingWhiteList;

};

UCLASS(MinimalAPI)
class UFortSettingsEditableStateHelper : public UObject
{
	GENERATED_BODY()

};

