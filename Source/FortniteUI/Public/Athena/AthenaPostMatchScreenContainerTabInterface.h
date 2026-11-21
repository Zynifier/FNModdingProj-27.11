// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaPostMatchScreenContainerTabInterface.generated.h"

class UObject;

USTRUCT()
struct FAthenaPostMatchScreenContainerTabInfo
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo")
	FText TabTitle;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo", meta=(AllowedClasses="/Script/Engine.MaterialInterface,/Script/Engine.Texture2D"))
	TSoftObjectPtr<UObject> TabIcon;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo", meta=(ClampMin="0"))
	int32 Order;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo")
	bool bDefaultInGameActiveTab;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo")
	bool bShowForSpectators;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo")
	FName AutoAdvanceToTabID;

	UPROPERTY(EditAnywhere, Category="AthenaPostMatchScreenContainerTabInfo")
	FName TabID;

};

UINTERFACE()
class UAthenaPostMatchScreenContainerTabInterface : public UInterface
{
	GENERATED_BODY()
};

class IAthenaPostMatchScreenContainerTabInterface
{
	GENERATED_BODY()

};

