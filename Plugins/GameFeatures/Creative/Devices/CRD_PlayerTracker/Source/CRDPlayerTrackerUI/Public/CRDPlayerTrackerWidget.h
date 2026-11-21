// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/AthenaPlayerIndicatorExtensionInterface.h"
#include "FortHUDElementWidget.h"
#include "CRDPlayerTrackerWidget.generated.h"

UCLASS(BlueprintType, Blueprintable, meta=(Category="Fortnite UI", ClassGroup="UI", DisableNativeTick))
class CRDPLAYERTRACKERUI_API UCRDPlayerTrackerWidget : public UFortHUDElementWidget, public IAthenaPlayerIndicatorExtensionInterface
{
	GENERATED_BODY()

};

