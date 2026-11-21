// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FortItemVariantHandle.h"
#include "FortCreativeItemVariantNotifierComponent.generated.h"

class UFortCreativeItemTemplate;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCreativeItemTemplateChanged, UFortCreativeItemTemplate*, ItemTemplate);

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortCreativeItemVariantNotifierComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category="Item Template")
	void BindToItemVariant(const FItemVariantHandle& VariantHandle);

	UFUNCTION(BlueprintPure, Category="Item Template")
	int32 GetNumBoundItemVariants() const;

	UFUNCTION(BlueprintPure, Category="Item Template")
	const FItemVariantHandle& GetReplicatedWeaponVariantHandle() const;

	UFUNCTION(BlueprintPure, Category="Item Template", meta=(DeterminesOutputType="TemplateClass", DynamicOutputParam="TemplateObjs"))
	bool GetTemplateObjects(TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled = true) const;

	UFUNCTION(BlueprintPure, Category="Item Template", meta=(DeterminesOutputType="TemplateClass", DynamicOutputParam="TemplateObjs"))
	bool GetTemplateObjectsByIndex(int32 VariantIndex, TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled = true) const;

	UFUNCTION(BlueprintPure, Category="Item Template", meta=(DeterminesOutputType="TemplateClass", DynamicOutputParam="TemplateObjs"))
	bool GetTemplateObjectsByVariant(const FItemVariantHandle& VariantHandle, TSubclassOf<UFortCreativeItemTemplate> TemplateClass, TArray<UFortCreativeItemTemplate*>& TemplateObjs, bool bOnlyEnabled = true) const;

	UFUNCTION(BlueprintCallable, Category="Item Template")
	void UnbindFromAllItemVariants();

	UFUNCTION(BlueprintCallable, Category="Item Template")
	void UnbindFromItemVariant(const FItemVariantHandle& VariantHandle);

	UPROPERTY(BlueprintAssignable, Category="Item Template")
	FCreativeItemTemplateChanged OnItemTemplateEnabled;

	UPROPERTY(BlueprintAssignable, Category="Item Template")
	FCreativeItemTemplateChanged OnItemTemplateDisabled;

	UPROPERTY(BlueprintAssignable, Category="Item Template")
	FCreativeItemTemplateChanged OnItemTemplateChanged;

protected:
	UPROPERTY(BlueprintReadOnly, Transient, Category="Item Template")
	TArray<FItemVariantHandle> BoundVariantHandles;

	UPROPERTY(Transient, Replicated)
	FItemVariantHandle WeaponVariantHandle;

};

