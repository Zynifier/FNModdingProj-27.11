// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OpenableInterface.generated.h"

class AController;

UINTERFACE(MinimalAPI)
class UOpenableInterface : public UInterface
{
	GENERATED_BODY()
};

class IOpenableInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Openable Interface")
	void Close(AController* ControllerInstigator);

	UFUNCTION(BlueprintNativeEvent, Category="Openable Interface")
	bool IsOpen() const;

	UFUNCTION(BlueprintNativeEvent, BlueprintAuthorityOnly, Category="Openable Interface")
	void Open(AController* ControllerInstigator, bool bRequestFastOpen);

};

