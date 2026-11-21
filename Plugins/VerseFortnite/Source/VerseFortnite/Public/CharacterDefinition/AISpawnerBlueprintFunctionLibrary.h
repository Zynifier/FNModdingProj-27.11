// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintAsyncActionBase.h"
#include "AISpawnerBlueprintFunctionLibrary.generated.h"

class UFortAthenaAISpawnerData;
class UFortAthenaAISpawnerDataComponentList;
class ULoadAndCreateComponentListAsync;
class ULoadNPCCharacterDefinitionAsync;
class UNPCCharacterDefinition;
class UNPCCharacterModifier;
class UObject;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCharacterDefinitionLoaded_BP, UNPCCharacterDefinition*, CharacterDefinition, TSubclassOf<UFortAthenaAISpawnerData>, AISpawnerData);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnComponentListCreated_BP, UNPCCharacterDefinition*, CharacterDefinition, TSubclassOf<UFortAthenaAISpawnerData>, AISpawnerData, UFortAthenaAISpawnerDataComponentList*, ComponentsList);

UCLASS()
class ULoadNPCCharacterDefinitionAsyncBase : public UBlueprintAsyncActionBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere, Category="LoadNPCCharacterDefinitionAsyncBase")
	TWeakObjectPtr<UNPCCharacterDefinition> LoadedCharacterDefinition;

	UPROPERTY()
	TWeakObjectPtr<UObject> ContextObject;

	UPROPERTY()
	TArray<UNPCCharacterModifier*> StoredAdditionalModifiers;

	UPROPERTY()
	TSoftObjectPtr<UNPCCharacterDefinition> StoredCharacterDefinition;

};

UCLASS()
class ULoadAndCreateComponentListAsync : public ULoadNPCCharacterDefinitionAsyncBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AISpawner", meta=(BlueprintInternalUseOnly="true", WorldContext="ContextObj"))
	static ULoadAndCreateComponentListAsync* LoadAndCreateComponentListAsync(UObject* ContextObj, TSoftObjectPtr<UNPCCharacterDefinition> CharacterDefinition, const TArray<UNPCCharacterModifier*>& AdditionalModifiers, const bool bForPreview);

	UPROPERTY(BlueprintAssignable)
	FOnComponentListCreated_BP OnFinished;

	UPROPERTY(VisibleAnywhere, Category="LoadAndCreateComponentListAsync")
	TWeakObjectPtr<UFortAthenaAISpawnerDataComponentList> ComponentsList;

protected:
	UPROPERTY()
	bool bStoredForPreview;

};

UCLASS()
class ULoadNPCCharacterDefinitionAsync : public ULoadNPCCharacterDefinitionAsyncBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="AISpawner", meta=(BlueprintInternalUseOnly="true", WorldContext="ContextObj"))
	static ULoadNPCCharacterDefinitionAsync* LoadCharacterDefinitionAsync(UObject* ContextObj, TSoftObjectPtr<UNPCCharacterDefinition> CharacterDefinition, const TArray<UNPCCharacterModifier*>& AdditionalModifiers);

	UPROPERTY(BlueprintAssignable)
	FOnCharacterDefinitionLoaded_BP OnLoaded;

};

