// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "FortEditorPreviewInterface.h"
#include "FortActorTemplatesComponent.generated.h"

class UActorTemplateResources;
class UFortPlaysetItemDefinition;
class UObject;

UENUM(BlueprintType)
enum class EValueCostCalculationMethod : uint8
{
	// Determines the cost of the Option Value based on the assets associated directly with it through the StructAssets

	Assets = 0,
	// Uses the cost of the most expensive sibling Option Value and includes it in the instance cost

	Max = 1,
	// Adds the entered InstancePayloadValue to the instance cost

	InstancePayload = 2,
};

USTRUCT(BlueprintType)
struct FDynamicTemplateOption
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="DynamicTemplateOption")
	FName OptionName;

	UPROPERTY(BlueprintReadWrite, Category="DynamicTemplateOption")
	TArray<TObjectPtr<UObject>> Objects;

};

USTRUCT()
struct FTemplateOptionValue
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FName Key;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOptionValue", meta=(Categories="Creative"))
	FGameplayTagQuery RequiredCondition;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOptionValue", meta=(Categories="Creative"))
	EValueCostCalculationMethod CalculationMethod;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOptionValue", meta=(StructTypeConst))
	FInstancedStruct StructAssets;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOptionValue", meta=(EditCondition="CalculationMethod==EValueCostCalculationMethod::InstancePayload", EditConditionHides))
	int32 InstancePayloadValue;

};

USTRUCT()
struct FTemplateOption
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="TemplateOption")
	FName OptionKey;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOption")
	bool bShouldMatchPreviousOption;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOption")
	TObjectPtr<UObject> StructType;

	UPROPERTY(EditDefaultsOnly, Category="TemplateOption")
	TArray<FTemplateOptionValue> OptionValues;

	UPROPERTY(Transient)
	TArray<FTemplateOptionValue> SortedOptionValues;

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class UActorTemplateResources : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="ActorTemplateResources")
	TArray<FTemplateOption> TemplateOptions;

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Transient, Category="Debug", meta=(DisplayAfter="bGenerateCSV", EditCondition="bGenerateCSV", EditConditionHides))
	TObjectPtr<UFortPlaysetItemDefinition> OwnerPID;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(EditDefaultsOnly, Category="Debug")
	bool bGenerateCSV;
#endif

};

UCLASS(MinimalAPI, BlueprintType, Blueprintable, ClassGroup=("Creative"), meta=(BlueprintSpawnableComponent))
class UFortActorTemplatesComponent : public UActorComponent, public IEditorPreviewInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetDynamicOption(FName OptionName, const TArray<UObject*>& Objects);

	UFUNCTION(BlueprintCallable)
	void SetDynamicOptions(const TArray<FDynamicTemplateOption>& Options);

	UFUNCTION()
	void UpdateDeviceProperties();

	UFUNCTION()
	void UpdateTemplateID();

	UPROPERTY(EditDefaultsOnly, Category="Template Data")
	TObjectPtr<UActorTemplateResources> TemplateResources;

private:
	UFUNCTION()
	void OnPropertiesLoaded();

};

