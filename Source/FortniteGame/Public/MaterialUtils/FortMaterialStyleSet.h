// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "FortMaterialStyleSet.generated.h"

class AActor;
class UFortMaterialStyle;
class UFortMaterialStyleSet;
class UMaterialInstanceDynamic;

UCLASS(meta=(ScriptName="FortMaterialStyleLibrary"))
class UFortMaterialStyleLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static bool ApplyStyleToMaterial(const UFortMaterialStyleSet* StyleSet, AActor* TargetActor, UMaterialInstanceDynamic* MaterialInstanceDynamic, FName DesiredStyleName, FName OptionalFallbackStyleName = NAME_None);

	UFUNCTION(BlueprintCallable)
	static const UFortMaterialStyle* ResolveStyleFromName(const UFortMaterialStyleSet* StyleSet, const AActor* TargetActor, FName DesiredStyleName, FName OptionalFallbackStyleName = NAME_None);

};

UCLASS(MinimalAPI, BlueprintType)
class UFortMaterialStyleSet : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Instanced, Category="FortMaterialStyleSet")
	TMap<FName, TObjectPtr<UFortMaterialStyle>> NameToMaterialStyle;

};

