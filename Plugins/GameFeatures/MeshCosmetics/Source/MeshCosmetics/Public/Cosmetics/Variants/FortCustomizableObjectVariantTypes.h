// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "Cosmetics/Variants/FortCosmeticVariantTypes.h"
#include "FortCustomizableObjectVariantTypes.generated.h"

class UCustomizableObject;
class UTexture2D;

USTRUCT(BlueprintType)
struct FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FString ParameterName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(ClampMin="-1"))
	int32 RangeIndex;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectBoolValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	bool Value;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TSoftObjectPtr<UCustomizableObject> ObjectToModify;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectBoolParamVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectBoolValue> Parameters;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectFloatValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(ClampMax="1", ClampMin="0"))
	float Value;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectFloatParamVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectFloatValue> Parameters;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectIntValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(ClampMin="-1"))
	int32 NumericValue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FString NamedValue;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectIntParamVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectIntValue> Parameters;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectMultilayerProjectsVirtualLayer
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	bool bModifyEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyEnabled", EditConditionHides))
	bool bEnabled;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	bool bModifyProjection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyProjection", EditConditionHides))
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyProjection", EditConditionHides))
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyProjection", EditConditionHides))
	FVector UpDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyProjection", EditConditionHides))
	FVector Scale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyProjection", EditConditionHides))
	float Angle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	bool bModifyImage;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyImage", EditConditionHides))
	FString Image;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	bool bModifyOpacity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(ClampMax="1.0", ClampMin="0.0", EditCondition="bModifyOpacity", EditConditionHides))
	float Opacity;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	bool bModifyOrder;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def", meta=(EditCondition="bModifyOrder", EditConditionHides))
	int32 Order;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectMultilayerProjectors
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TMap<FName, FCustomizableObjectMultilayerProjectsVirtualLayer> VirtualLayers;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectMultilayerProjectorVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TMap<FName, FCustomizableObjectMultilayerProjectors> MultilayerProjectors;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectProjectorValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FVector Position;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FVector Direction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FVector UpDirection;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FVector Scale;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	float Angle;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectProjectorVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectProjectorValue> Parameters;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectStateValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FString NewState;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectStateVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectStateValue> States;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectTextureValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	UTexture2D* Value;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectTextureParamVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectTextureValue> Parameters;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectVectorValue : public FCustomizableObjectValueBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	FLinearColor Value;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectVectorParamVariant : public FCustomizableObjectParamVariantBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectVectorValue> Parameters;

};

USTRUCT(BlueprintType)
struct FCustomizableObjectParamsVariantDef : public FBaseVariantDef
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectIntParamVariant> IntParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectFloatParamVariant> FloatParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectBoolParamVariant> BoolParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectVectorParamVariant> VectorParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectTextureParamVariant> TextureParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectProjectorVariant> ProjectorParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectMultilayerProjectorVariant> MultilayerProjectorParams;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Variant Def")
	TArray<FCustomizableObjectStateVariant> StateVariants;

};

