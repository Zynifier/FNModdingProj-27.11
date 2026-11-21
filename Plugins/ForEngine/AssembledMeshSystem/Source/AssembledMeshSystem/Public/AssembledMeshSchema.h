// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "InstancedStruct.h"
#include "Math/MathFwd.h"
#include "AssembledMeshSchema.generated.h"

class UAnimInstance;
class UCustomizableObject;
class UCustomizableObjectInstance;

USTRUCT()
struct FAssembledMeshAttachmentRules
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="AttachmentRules")
	FName AttachSocketName;

	UPROPERTY(EditAnywhere, Category="AttachmentRules")
	FVector AttachOffset;

	UPROPERTY(EditAnywhere, Category="AttachmentRules")
	FRotator AttachRotation;

	UPROPERTY(EditAnywhere, Category="AttachmentRules")
	FVector AttachScale;

};

USTRUCT()
struct FBaseParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="BaseParamData")
	FString ParamName;

};

USTRUCT()
struct FFloatParamData : public FBaseParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="FloatParamData")
	float FloatValue;

	UPROPERTY(VisibleAnywhere, Category="FloatParamData")
	float MinFloatValue;

	UPROPERTY(VisibleAnywhere, Category="FloatParamData")
	float MaxFloatValue;

};

USTRUCT()
struct FIntParamData : public FBaseParamData
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, Category="IntParamData")
	TArray<FString> ParamOptions;

};

UCLASS(BlueprintType)
class ASSEMBLEDMESHSYSTEM_API UAssembledMeshSchema : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
#if WITH_EDITOR
	UFUNCTION(BlueprintPure)
	TSoftObjectPtr<UCustomizableObjectInstance> GetCustomizableObjectInstance() const;
#endif

#if WITH_EDITOR
	UFUNCTION(BlueprintCallable)
	void SetCustomizableObjectInstance(TSoftObjectPtr<UCustomizableObjectInstance> InCustomizableObjectInstance);
#endif

	UPROPERTY(EditDefaultsOnly, Category="Defaults")
	FGameplayTag MeshSchemaTag;

	UPROPERTY(EditDefaultsOnly, Category="Instance Customizable Object")
	TSoftObjectPtr<UCustomizableObjectInstance> CustomizableObjectInstance;

	UPROPERTY(EditDefaultsOnly, Category="Customizable Object")
	TSoftObjectPtr<UCustomizableObject> CustomizableObject;

	UPROPERTY()
	TMap<FString, FString> SelectedIntParams;

	UPROPERTY()
	TMap<FString, float> SelectedFloatParams;

	UPROPERTY(EditDefaultsOnly, Category="Attachment Rules")
	FAssembledMeshAttachmentRules AttachmentRules;

	UPROPERTY(EditDefaultsOnly, Category="Animation")
	TSoftClassPtr<UAnimInstance> AnimClass;

	UPROPERTY(EditDefaultsOnly, Category="Sound Library")
	FGameplayTagContainer SoundLibraryTags;

	UPROPERTY(EditDefaultsOnly, Category="AssembledMeshSchema", meta=(BaseStruct="/Script/AssembledMeshSystem.AssembledMeshSchemaData", ExcludeBaseStruct))
	TArray<FInstancedStruct> AdditionalData;

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TObjectPtr<UCustomizableObjectInstance> TempInstance;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<FIntParamData> IntParams;
#endif

#if WITH_EDITORONLY_DATA
	UPROPERTY(Transient)
	TArray<FFloatParamData> FloatParams;
#endif

};

