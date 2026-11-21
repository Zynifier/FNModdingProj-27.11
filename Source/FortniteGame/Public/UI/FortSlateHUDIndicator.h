// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/FortActorIndicatorInterface.h"
#include "UI/FortIndicator.h"
#include "FortSlateHUDIndicator.generated.h"

UCLASS()
class UFortSlateHUDIndicator : public UFortIndicator, public IFortActorIndicatorInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	bool bClampToScreen;

	UPROPERTY(Transient)
	bool bShowClampToScreenArrow;

};

