// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Map/AthenaMapNavigableIconCustom.h"
#include "AthenaMapCollectionIcon.generated.h"

class UObject;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaMapCollectionIcon : public UAthenaMapNavigableIconCustom
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	void SetIsKnown(const bool bIsKnown);

	UFUNCTION(BlueprintImplementableEvent)
	void SetSecondaryIcon(const TSoftObjectPtr<UObject>& SecondaryIcon);

};

