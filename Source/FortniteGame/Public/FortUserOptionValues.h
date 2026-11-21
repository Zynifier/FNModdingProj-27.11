// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortUserOptionValues.generated.h"

class APlayerController;
class IUserOptionDefinitionContainerInterface;

UINTERFACE(MinimalAPI, BlueprintType, meta=(CannotImplementInterfaceInBlueprint))
class UUserOptionValuesInterface : public UInterface
{
	GENERATED_BODY()
};

class FORTNITEGAME_API IUserOptionValuesInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="UserOptionValues", meta=(DisplayName="Get User Option Definitions", ScriptName="GetUserOptionDefinitions"))
	virtual TScriptInterface<IUserOptionDefinitionContainerInterface> BP_GetUserOptionDefinitions() const;

	UFUNCTION(BlueprintCallable, Category="UserOptionValues")
	virtual bool GetUserOptionValue(const FString& UserOptionKey, FString& UserOptionValue) const;

	UFUNCTION(BlueprintCallable, Category="UserOptionValues")
	virtual bool GetUserOptionValues(TMap<FString, FString>& UserOptionValues) const;

	UFUNCTION(BlueprintCallable, Category="UserOptionValues")
	virtual bool SetUserOptionValue(APlayerController* PlayerController, const FString& UserOptionKey, const FString& UserOptionValue);

	UFUNCTION(BlueprintCallable, Category="UserOptionValues")
	virtual bool SetUserOptionValues(APlayerController* PlayerController, const TMap<FString, FString>& UserOptionValues);

};

