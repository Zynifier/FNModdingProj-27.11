// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Valkyrie/FortExposedAssetProviderInterface.h"
#include "FortExposedAssetProviderLibrary.generated.h"

class UObject;

UCLASS()
class UFortExposedAssetProviderLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="ExposedAssetProvider")
	static void AddVersion(UPARAM(ref) FFortExposedAssetProviderVersion& VersionRef, const int32 Version);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="ExposedAssetProvider", meta=(CustomStructureParam="Property", DefaultToSelf="Object"))
	static void CollectClassSparseDataAssetPropertyReferences(UPARAM(ref) FFortExposedAssetReferenceCollector& CollectorRef, UObject* Object, const int32& Property);
	DECLARE_FUNCTION(execCollectClassSparseDataAssetPropertyReferences);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="ExposedAssetProvider", meta=(CustomStructureParam="Property", DefaultToSelf="Object"))
	static void CollectClassSparseDataClassPropertyReferences(UPARAM(ref) FFortExposedClassReferenceCollector& CollectorRef, UObject* Object, const int32& Property);
	DECLARE_FUNCTION(execCollectClassSparseDataClassPropertyReferences);

	UFUNCTION(BlueprintCallable, Category="ExposedAssetProvider")
	static void CollectIndirectAssetReference(UPARAM(ref) FFortExposedAssetReferenceCollector& CollectorRef, const TSoftObjectPtr<UObject>& Value);

	UFUNCTION(BlueprintCallable, Category="ExposedAssetProvider")
	static void CollectIndirectClassReference(UPARAM(ref) FFortExposedClassReferenceCollector& CollectorRef, const TSoftClassPtr<UObject>& Value);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="ExposedAssetProvider", meta=(CustomStructureParam="Property", DefaultToSelf="Object"))
	static void CollectObjectPropertyAssetReferences(UPARAM(ref) FFortExposedAssetReferenceCollector& CollectorRef, UObject* Object, const int32& Property);
	DECLARE_FUNCTION(execCollectObjectPropertyAssetReferences);

	UFUNCTION(CustomThunk, BlueprintCallable, Category="ExposedAssetProvider", meta=(CustomStructureParam="Property", DefaultToSelf="Object"))
	static void CollectObjectPropertyClassReferences(UPARAM(ref) FFortExposedClassReferenceCollector& CollectorRef, UObject* Object, const int32& Property);
	DECLARE_FUNCTION(execCollectObjectPropertyClassReferences);

};

