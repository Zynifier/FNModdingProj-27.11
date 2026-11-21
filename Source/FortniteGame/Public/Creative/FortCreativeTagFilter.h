// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Creative/FortCreativeTags.h"
#include "FortCreativeTagFilter.generated.h"

class UEditableCreativeTagQueryExpression;

UCLASS(Abstract, EditInlineNew, CollapseCategories)
class UEditableCreativeTagQueryExpression : public UObject
{
	GENERATED_BODY()

};

UCLASS(BlueprintType, meta=(DisplayName="All Expressions Match"))
class UEditableCreativeTagQueryExpression_AllExprMatch : public UEditableCreativeTagQueryExpression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Expr")
	TArray<TObjectPtr<UEditableCreativeTagQueryExpression>> Expressions;

};

UCLASS(BlueprintType, meta=(DisplayName="All Tags Match"))
class UEditableCreativeTagQueryExpression_AllTagsMatch : public UEditableCreativeTagQueryExpression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Expr")
	FFortCreativeTagsHelper Tags;

};

UCLASS(BlueprintType, meta=(DisplayName="Any Expressions Match"))
class UEditableCreativeTagQueryExpression_AnyExprMatch : public UEditableCreativeTagQueryExpression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Expr")
	TArray<TObjectPtr<UEditableCreativeTagQueryExpression>> Expressions;

};

UCLASS(BlueprintType, meta=(DisplayName="Any Tags Match"))
class FORTNITEGAME_API UEditableCreativeTagQueryExpression_AnyTagsMatch : public UEditableCreativeTagQueryExpression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Expr")
	FFortCreativeTagsHelper Tags;

};

UCLASS(BlueprintType, meta=(DisplayName="No Expressions Match"))
class UEditableCreativeTagQueryExpression_NoExprMatch : public UEditableCreativeTagQueryExpression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Instanced, Category="Expr")
	TArray<TObjectPtr<UEditableCreativeTagQueryExpression>> Expressions;

};

UCLASS(BlueprintType, meta=(DisplayName="No Tags Match"))
class UEditableCreativeTagQueryExpression_NoTagsMatch : public UEditableCreativeTagQueryExpression
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="Expr")
	FFortCreativeTagsHelper Tags;

};

UCLASS(EditInlineNew)
class FORTNITEGAME_API UFortCreativeTagFilter : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Instanced, Category="Query")
	TObjectPtr<UEditableCreativeTagQueryExpression> RootExpression;

};

