// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Math/MathFwd.h"
#include "UObject/NoExportTypes.h"
#include "Effects/FortNiagaraCascadeMigration.h"
#include "FortVFXMarshallingTypes.generated.h"

class UFXSystemAsset;
class UFXSystemComponent;
class USceneComponent;

USTRUCT(BlueprintType)
struct FMarshalledVFXData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="Parameters", meta=(Categories="GameplayVFX"))
	FGameplayTagContainer ParameterGroups;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="System")
	EFXType Type;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="System")
	TSoftObjectPtr<UFXSystemAsset> Asset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="System|Attachment")
	FName AttachAtBone;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="System|Attachment")
	FTransform RelativeOffset;

	UPROPERTY(EditDefaultsOnly, Category="Linking", meta=(Categories="GameplayVFX"))
	FGameplayTag EffectIdTag;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="System")
	bool bAutoActivate;

};

USTRUCT(BlueprintType)
struct FParameterNameMapping
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mapping")
	FName CascadeName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mapping")
	FName NiagaraName;

};

USTRUCT(BlueprintType)
struct FMarshalledVFXAuthoredData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TArray<FMarshalledVFXData> NiagaraVFX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Config")
	TArray<FMarshalledVFXData> CascadeVFX;

	UPROPERTY(EditAnywhere, Category="Config")
	TMap<FName, FParameterNameMapping> NameReplacements;

};

USTRUCT(BlueprintType)
struct FMarshalledVFXRuntimeData
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFXSystemComponent>> DynamicSystems;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<USceneComponent> BasedOn;

};

UINTERFACE(meta=(CannotImplementInterfaceInBlueprint))
class UFortVFXDataOwner : public UInterface
{
	GENERATED_BODY()
};

class IFortVFXDataOwner
{
	GENERATED_BODY()

};

UCLASS(DefaultToInstanced, EditInlineNew, BlueprintType, Blueprintable, AutoExpandCategories=("Default"), meta=(DisplayName="Default Authored Data Preset"))
class UMarshalledVFX_AuthoredDataConfig : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Default")
	FMarshalledVFXAuthoredData Data;

};

