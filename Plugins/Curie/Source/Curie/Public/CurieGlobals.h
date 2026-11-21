// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/SoftObjectPath.h"
#include "CurieGlobals.generated.h"

class UCurieManager;
class UWorld;

UCLASS(Config=Game)
class CURIE_API UCurieGlobals : public UObject
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	bool bEnableCurie;

	UPROPERTY(Config)
	FSoftClassPath CurieGlobalsClassName;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<TObjectPtr<UWorld>, TObjectPtr<UCurieManager>> RegisteredCurieManagers;
#endif

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<UCurieManager> RegisteredCurieManager;

};

