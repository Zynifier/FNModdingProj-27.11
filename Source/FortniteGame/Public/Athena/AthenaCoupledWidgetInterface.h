// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AthenaCoupledWidgetInterface.generated.h"

class UObject;

UINTERFACE(MinimalAPI, BlueprintType)
class UAthenaCoupledWidgetInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IAthenaCoupledWidgetInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, Category="Coupling")
	void BindTo(UObject* AssociatedObject);

	UFUNCTION(BlueprintNativeEvent, Category="Coupling")
	void UnbindFrom(UObject* AssociatedObject);

};

