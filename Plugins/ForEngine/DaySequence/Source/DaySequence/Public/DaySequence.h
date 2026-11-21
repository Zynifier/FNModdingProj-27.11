// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Interfaces/Interface_AssetUserData.h"
#include "MovieSceneSequence.h"
#include "DaySequenceBindingReference.h"
#include "DaySequence.generated.h"

class UAssetUserData;
class UBlueprint;
class UMovieScene;
class UObject;

UCLASS(BlueprintType, HideCategories=("Object"))
class DAYSEQUENCE_API UDaySequence : public UMovieSceneSequence, public IInterface_AssetUserData
{
	GENERATED_BODY()

public:
	UDaySequence(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UMovieScene> MovieScene;

protected:
	UPROPERTY()
	FDaySequenceBindingReferences BindingReferences;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UBlueprint> DirectorBlueprint;
#endif

	UPROPERTY()
	TSubclassOf<UObject> DirectorClass;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Instanced, Category="Animation")
	TArray<TObjectPtr<UAssetUserData>> AssetUserData;

};

