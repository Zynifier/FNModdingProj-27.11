// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortMobileHUDContextLayout.generated.h"

class UFortMobileHUDContextModel;

USTRUCT()
struct FFortMobileHUDContextLayout
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TObjectPtr<UFortMobileHUDContextModel> HUDContextModel;

};

