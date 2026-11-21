// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Bacchus/LayoutProfile/FortMobileHUDContextLayout.h"
#include "FortMobileHUDLayoutProfile.generated.h"

USTRUCT()
struct FFortMobileHUDLayoutProfile
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	FText ProfileName;

	UPROPERTY(Transient)
	TArray<FFortMobileHUDContextLayout> ContextLayouts;

};

