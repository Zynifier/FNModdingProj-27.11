// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Collections/FortCollectionData.h"
#include "FortCollectionData_Character.generated.h"

class UFortTandemCharacterData;

UCLASS(Config=Game, MinimalAPI)
class UFortCollectionDataCharacter : public UFortCollectionData
{
	GENERATED_BODY()

protected:
	UPROPERTY(Config)
	TArray<TSoftObjectPtr<UFortTandemCharacterData>> EntriesToDisableViaHotfix;

private:
#if WITH_EDITOR
	UFUNCTION(Exec, Category="QuickAdd", meta=(CallInEditor="true"))
	void CreateDataFromDataStr();
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditInstanceOnly, Transient, AdvancedDisplay, Category="QuickAdd", meta=(ColumnWidth="150", DisplayAfter="Entries", MultiLine="true"))
	FString CreateCsvDataStr;
#endif

};

UCLASS(MinimalAPI, AutoExpandCategories=("Character"))
class UFortCollectionDataEntryCharacter : public UFortCollectionDataEntry
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Character")
	TSoftObjectPtr<UFortTandemCharacterData> CharacterData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(VisibleDefaultsOnly, Transient, Category="Character")
	FText EntryName;
#endif

};

