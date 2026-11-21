// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Athena/AthenaMapScreenContainerTabInterface.h"
#include "AthenaMapScreenTabBase.generated.h"

UCLASS(MinimalAPI)
class UAthenaMapScreenTabBase : public UCommonActivatableWidget, public IAthenaMapScreenContainerTabInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Fullscreen Map")
	FAthenaMapScreenContainerTabInfo MapTabInfo;

};

