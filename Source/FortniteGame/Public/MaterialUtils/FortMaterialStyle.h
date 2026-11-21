// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "FortMaterialStyle.generated.h"

class AActor;
class UFortMaterialStyleComponent;
class UMaterialInstanceDynamic;
class UTexture;

UENUM(BlueprintType)
enum class EMaterialStyleParameterType : uint8
{
	/** Modify a scalar parameter of a dynamic material instance */
	Scalar = 0,
	/** Modify a vector parameter of a dynamic material instance */
	Vector = 1,
	/** Modify a texture parameter of a dynamic material instance */
	Texture = 2,
};

USTRUCT(BlueprintType)
struct FFortMaterialStyleApplyParams
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="FortMaterialStyleApplyParams")
	TObjectPtr<UMaterialInstanceDynamic> MaterialInstanceDynamic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Category="FortMaterialStyleApplyParams")
	TObjectPtr<AActor> TargetActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Transient, Export, Category="FortMaterialStyleApplyParams", meta=(EditInline="true"))
	TObjectPtr<UFortMaterialStyleComponent> TargetMaterialStyleComponent;

};

USTRUCT(BlueprintType)
struct FFortMaterialStyleParameterData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMaterialStyleParameterData")
	EMaterialStyleParameterType DataType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMaterialStyleParameterData")
	FName Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMaterialStyleParameterData")
	float Scalar;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMaterialStyleParameterData")
	FLinearColor Vector;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortMaterialStyleParameterData")
	TObjectPtr<UTexture> Texture;

};

UCLASS(Abstract, EditInlineNew, BlueprintType, Blueprintable)
class UFortMaterialStyle : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent)
	void ApplyTo(const FFortMaterialStyleApplyParams& Params) const;

};

