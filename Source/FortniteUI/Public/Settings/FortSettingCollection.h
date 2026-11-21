// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/FortSetting.h"
#include "FortSettingCollection.generated.h"

class UFortSetting;

UCLASS(MinimalAPI)
class UFortSettingCollection : public UFortSetting
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortSetting>> Settings;

};

UCLASS()
class UFortSettingCollectionPage : public UFortSettingCollection
{
	GENERATED_BODY()

};

