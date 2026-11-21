// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "FortTabInterface.h"
#include "FortTabListWidgetBase.h"
#include "VkEditLogTab.generated.h"

UCLASS(MinimalAPI, meta=(DisableNativeTick))
class UVkEditLogTab : public UCommonActivatableWidget, public IFortTabInterface, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="VkEditLogTab")
	FFortTabButtonLabelInfo TabButtonLabelInfo;

	UPROPERTY(EditDefaultsOnly, Category="VkEditLogTab")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

};

