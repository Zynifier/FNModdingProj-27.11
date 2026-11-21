// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PlayspaceLibrary.generated.h"

class AActor;
class APlayspace;
class UObject;

UCLASS(meta=(ScriptName="PlayspaceLibrary"))
class PLAYSPACESYSTEM_API UPlayspaceLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void DestroyPlayspace(APlayspace* PlayspaceToDestroy);

	UFUNCTION(BlueprintCallable)
	static APlayspace* GetPlayspaceForActor(const UObject* WorldContextObject, AActor* InActor);

};

