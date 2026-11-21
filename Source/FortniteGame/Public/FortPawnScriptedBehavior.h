// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "FortPawnScriptedBehavior.generated.h"

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScriptedBehaviorScriptComplete);

USTRUCT()
struct FScriptedAction
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Template;

	UPROPERTY()
	TArray<FString> Params;

	UPROPERTY(Transient)
	TMap<FString, FString> ParamMap;

};

USTRUCT()
struct FScriptedBehavior
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString ScriptName;

	UPROPERTY()
	TArray<FScriptedAction> Actions;

};

UCLASS(Config=Game)
class UFortPawnScriptedBehavior : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<FScriptedAction> ActionTemplates;

	UPROPERTY(Config)
	TArray<FScriptedBehavior> ScriptedBehaviors;

	UPROPERTY()
	FScriptedBehavior CurrentBehavior;

	UPROPERTY()
	FScriptedAction CurrentCommand;

	UPROPERTY()
	FScriptedBehaviorScriptComplete ScriptComplete;

private:
	UFUNCTION()
	void PlaceStructure();

};

