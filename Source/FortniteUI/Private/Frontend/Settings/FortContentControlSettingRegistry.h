// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Settings/Registry/FortSettingRegistry.h"
#include "FortContentControlSettingRegistry.generated.h"

class UFortSettingCollection;

UCLASS()
class UFortContentControlSettingRegistry : public UFortSettingRegistry
{
	GENERATED_BODY()

protected:
	UPROPERTY()
	TObjectPtr<UFortSettingCollection> ContentControlSettings;

};

