// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DoorInterface.generated.h"

class AController;

UINTERFACE(MinimalAPI)
class UDoorInterface : public UInterface
{
	GENERATED_BODY()
};

class IDoorInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Door Interface")
	void CloseDoorStart(AController* ControllerInstigator);

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Door Interface")
	bool IncludesDoors() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Door Interface")
	bool IsDoorClosed() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Door Interface")
	void OpenDoorStart(AController* ControllerInstigator);

};

