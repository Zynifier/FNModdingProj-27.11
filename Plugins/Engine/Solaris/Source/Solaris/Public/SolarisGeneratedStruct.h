// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Misc/Guid.h"
#include "UObject/NoExportTypes.h"
#include "SolarisGeneratedStruct.generated.h"

class UObject;
class UStructCookedMetaData;

UCLASS()
class SOLARIS_API UVerseStruct : public UObject
{
	GENERATED_BODY()

public:
	/** EVerseClassFlags */
	UPROPERTY()
	uint32 VerseClassFlags;

	/** Function used for initialization */
	UPROPERTY()
	TObjectPtr<UObject> InitFunction;

	/** Parent module class */
	UPROPERTY()
	TSubclassOf<UObject> ModuleClass;

	/** GUID to be able to match old version of this struct to new one */
	UPROPERTY()
	FGuid Guid;

	UPROPERTY()
	TObjectPtr<UObject> FactoryFunction;

	UPROPERTY()
	TObjectPtr<UObject> OverrideFactoryFunction;

private:
#if WITH_EDITORONLY_DATA
	UPROPERTY()
	TObjectPtr<UStructCookedMetaData> CachedCookedMetaDataPtr;
#endif

};

