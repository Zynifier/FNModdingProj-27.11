// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MaterialTypes.h"
#include "FortEditorUtilityLibrary.generated.h"

class UMaterial;
class UMaterialInstance;
class UObject;

UCLASS()
class UFortEditorUtilityLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Development|Editor")
	static void ExitEditor();

	UFUNCTION(BlueprintCallable, Category="Development|Editor")
	static UObject* FindServerPlayWorld();

	UFUNCTION(BlueprintCallable, Category="Development|Editor")
	static void GetAvailableMaterialParameters(const UMaterial* Material, UMaterialInstance* MaterialInstance, TArray<FMaterialParameterInfo>& VisibleExpressions);

	UFUNCTION(BlueprintCallable, Category="Development|Editor")
	static bool IsMaterialParameterAvailable(UMaterialInstance* MaterialInstance, FName ParameterName);

	UFUNCTION(BlueprintCallable, Category="Development|Editor")
	static bool SaveAssetsWhilePlaying(const TArray<UObject*>& AssetsToSave, bool bOnlyIfIsDirty);

};

