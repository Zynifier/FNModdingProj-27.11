// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MeshCosmetics_ApparelEditorHelpers.generated.h"

class UAthenaCosmeticItemDefinition;

UCLASS(meta=(Namespace="Fortnite.Cosmetics.MeshCosmetics.Apparel"))
class UMeshCosmetics_ApparelEditorHelpers : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="MeshCosmetics|EditorHelpers")
	static void CreateApparelForCosmetics(TArray<UAthenaCosmeticItemDefinition*> Cosmetics);

};

