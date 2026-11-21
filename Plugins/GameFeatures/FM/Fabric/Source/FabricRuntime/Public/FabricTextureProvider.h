// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "UObject/NoExportTypes.h"
#include "FabricTextureProvider.generated.h"

class UFabricTextureTreeNode;
class UTexture;

USTRUCT(BlueprintType)
struct FABRICRUNTIME_API FFabricTextureProviderTexture
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, Category="FabricTextureProviderTexture")
	TObjectPtr<UTexture> Texture;

	UPROPERTY(BlueprintReadWrite, Category="FabricTextureProviderTexture")
	FLinearColor Tint;

};

UCLASS(BlueprintType, Blueprintable)
class FABRICRUNTIME_API UFabricTextureProviderBase : public UObject
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTextureChanged, const FFabricTextureProviderTexture&, Texture);

public:
	UFUNCTION(BlueprintCallable)
	void SetSourceTexture(const FFabricTextureProviderTexture& InTexture);

	UPROPERTY(BlueprintAssignable)
	FOnTextureChanged OnTextureChanged;

protected:
	UPROPERTY(Transient)
	FFabricTextureProviderTexture SourceTexture;

	UPROPERTY(Transient)
	float CurrentCableFloatValue;

	UPROPERTY(Transient)
	float CurrentCableFloatDirection;

	UPROPERTY(Transient)
	float TimeElapsedSinceLastCableFloatDirty;

	UPROPERTY(Transient)
	bool bCurrentCableFloatDirty;

};

UCLASS(BlueprintType)
class FABRICRUNTIME_API UFabricTextureTreeNode : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void CopyProperties(const UFabricTextureTreeNode* Other);

	UFUNCTION(BlueprintCallable)
	void Reset();

	UPROPERTY(BlueprintReadWrite, Category="FabricTextureTreeNode")
	TArray<UFabricTextureTreeNode*> Children;

protected:
	UPROPERTY(BlueprintReadOnly, Category="FabricTextureTreeNode")
	FFabricTextureProviderTexture Texture;

};

