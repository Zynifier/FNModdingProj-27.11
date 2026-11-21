// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaMapNavigableIcon.h"
#include "AthenaMapNavigableIconCustom.generated.h"

class UObject;

UCLASS(Abstract, MinimalAPI, meta=(Category="Fortnite UI", DisableNativeTick))
class UAthenaMapNavigableIconCustom : public UAthenaMapNavigableIcon
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEUI_API void SetIcon(const TSoftObjectPtr<UObject>& Icon);

};

